/**
 * @file gnh_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for uipbuf_get_next_header
 * @version 0.1
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"

void harness() {

    // Define input buffer size:

    uint16_t isize;

    // Define minimum size:

    __CPROVER_assume(isize >= sizeof(struct uip_ip_hdr));

    // Allocate buffer of previous size:

    uint8_t *buff = (uint8_t *)malloc(sizeof(uint8_t) * isize);

    // Buffer won't be NULL:

    __CPROVER_assume(buff != NULL);

    // Define unconstrained protocol char
    // (Maybe set to 0? Will be overwritten?)

    uint8_t proto;

    // Unconstrained bool:

    bool start;

    uipbuf_get_next_header(buff, isize, &proto, start);
}
