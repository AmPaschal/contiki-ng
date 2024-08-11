/**
 * @file vuln-uipbuf-get-next-header.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Vulnerability reproduction for uipbuf_get_next_header
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uipbuf.h"

#include <stdio.h> /* For printf() */
#include <stdlib.h>

/*---------------------------------------------------------------------------*/
PROCESS(uipbuf_vuln_process, "UIP Buff Vuln Process");
AUTOSTART_PROCESSES(&uipbuf_vuln_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(uipbuf_vuln_process, ev, data)
{
    PROCESS_BEGIN();

    // Define input buffer size:

    uint16_t isize = 1;

    // Allocate buffer of unconstrained size:

    uint8_t *buff = (uint8_t *)malloc(sizeof(uint8_t) * isize);

    // Define unconstrained protocol char

    uint8_t proto = 0;

    // Unconstrained bool:

    bool start = false;

    uipbuf_get_next_header(buff, isize, &proto, start);

    printf("Done");

    exit(0);

    PROCESS_END();
}
/*---------------------------------------------------------------------------*/
