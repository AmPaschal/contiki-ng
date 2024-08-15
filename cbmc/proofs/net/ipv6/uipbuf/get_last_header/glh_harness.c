/**
 * @file glh_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for uipbuf_get_last_header
 * @version 0.1
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include <stdlib.h>

void harness() {

    // Define input buffer size:

    const uint16_t isize;

    // Define minimum size:

    // __CPROVER_assume(isize >= sizeof(struct uip_ip_hdr));

    // Define maximum size:

    __CPROVER_assume(isize <= 200);

    // Allocate buffer of unconstrained size:

    // uint8_t *buff = (uint8_t *)malloc(sizeof(uint8_t) * isize);

    uint8_t buff[isize];

    // Buffer won't be NULL:

    __CPROVER_assume(buff != NULL);

    // Define unconstrained protocol char

    uint8_t proto = 0;

    uint8_t* head = uipbuf_get_last_header(buff, isize, &proto);
}
