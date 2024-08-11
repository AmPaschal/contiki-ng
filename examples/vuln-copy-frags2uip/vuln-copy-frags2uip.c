/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include <stdlib.h>

#include "contiki.h"

#include "dev/watchdog.h"
#include "net/link-stats.h"
#include "net/ipv6/uipopt.h"
#include "net/ipv6/tcpip.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/ipv6/uipbuf.h"
#include "net/ipv6/sicslowpan.h"
#include "net/netstack.h"
#include "net/packetbuf.h"
#include "net/queuebuf.h"

#include "net/routing/routing.h"

#include "sys/log.h"
#define LOG_MODULE "6LoWPAN"
#define LOG_LEVEL LOG_LEVEL_6LOWPAN

#include <stdio.h> /* For printf() */

#define SICSLOWPAN_REASS_CONTEXTS 2

#define SICSLOWPAN_FIRST_FRAGMENT_SIZE (SICSLOWPAN_FRAGMENT_SIZE + 38)

#define SICSLOWPAN_FRAGMENT_BUFFERS 12

#define SICSLOWPAN_FRAGMENT_SIZE (127 - 2 - 15)

struct sicslowpan_frag_info
{
  /** When reassembling, the source address of the fragments being merged */
  linkaddr_t sender;
  /** When reassembling, the tag in the fragments being merged. */
  uint16_t tag;
  /** Total length of the fragmented packet */
  uint16_t len;
  /** Current length of reassembled fragments */
  uint16_t reassembled_len;
  /** Reassembly %process %timer. */
  struct timer reass_timer;

  /** Fragment size of first fragment */
  uint16_t first_frag_len;
  /** First fragment - needs a larger buffer since the size is uncompressed size
   and we need to know total size to know when we have received last fragment. */
  uint8_t first_frag[SICSLOWPAN_FIRST_FRAGMENT_SIZE];
};

struct sicslowpan_frag_buf
{
  /* the index of the frag_info */
  uint8_t index;
  /* Fragment offset */
  uint8_t offset;
  /* Length of this fragment (if zero this buffer is not allocated) */
  uint8_t len;
  uint8_t data[SICSLOWPAN_FRAGMENT_SIZE];
};

struct sicslowpan_frag_buf frag_buf[SICSLOWPAN_FRAGMENT_BUFFERS];

struct sicslowpan_frag_info frag_info[SICSLOWPAN_REASS_CONTEXTS];

int clear_fragments(uint8_t frag_info_index) { return 0; }

bool copy_frags2uip(int context)
{
  int i;

  /* Check length fields before proceeding. */
  if (frag_info[context].len < frag_info[context].first_frag_len ||
      frag_info[context].len > sizeof(uip_buf))
  {
    printf("Bad\n");
    LOG_WARN("input: invalid total size of fragments\n");
    clear_fragments(context);
    return false;
  }

  /* Copy from the fragment context info buffer first */
  memcpy((uint8_t *)UIP_IP_BUF, (uint8_t *)frag_info[context].first_frag,
         frag_info[context].first_frag_len);

  printf("First Copy\n");

  /* Ensure that no previous data is used for reassembly in case of missing fragments. */
  memset((uint8_t *)UIP_IP_BUF + frag_info[context].first_frag_len, 0,
         frag_info[context].len - frag_info[context].first_frag_len);

  for (i = 0; i < SICSLOWPAN_FRAGMENT_BUFFERS; i++)
  {
    /* And also copy all matching fragments */
    if (frag_buf[i].len > 0 && frag_buf[i].index == context)
    {
      if (((size_t)frag_buf[i].offset << 3) + frag_buf[i].len > sizeof(uip_buf))
      {
        LOG_WARN("input: invalid fragment offset\n");
        clear_fragments(context);
        return false;
      }
      memcpy((uint8_t *)UIP_IP_BUF + (uint16_t)(frag_buf[i].offset << 3),
             (uint8_t *)frag_buf[i].data, frag_buf[i].len);
    }
  }
  /* deallocate all the fragments for this context */
  clear_fragments(context);

  return true;
}

/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "SNMP Vuln Process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data) {

  PROCESS_BEGIN();

  // Define a context:

  int context = 0;

  // Set a dangerous size:

  frag_info[context].first_frag_len = 1000;
  frag_info[context].len = frag_info[context].first_frag_len + 10;

  // uint8_t blah[1000];

  // uint8_t *tarr = (uint8_t *)malloc(50);

  // memcpy(blah, tarr, frag_info[context].first_frag_len);

  // Call function:

  copy_frags2uip(context);

  printf("Done");

  exit(0);

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
