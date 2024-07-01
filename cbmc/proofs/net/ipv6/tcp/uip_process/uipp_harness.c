/**
 * @file uipp_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for TCP uip_process
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"

extern struct uip_udp_conn *uip_udp_conn;
extern uint16_t uip_len;
uint16_t uip_ext_len;  // Define header extension length

uint16_t chksum(uint16_t sum, const uint8_t *data, uint16_t len) {

    // Just return some unconstrained sum:

    uint16_t sum;

    return sum;
}

void harness() {

    // Allocate udp connection data:

    uip_udp_conn = (struct uip_udp_conn*)malloc(sizeof(struct uip_udp_conn));

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Header length will not exceed uip_len:

    __CPROVER_assume(uip_ext_len <= uip_len);

    // Total length of extension headers will not exceed buffer size:

    // __CPROVER_assume(uip_l3_icmp_hdr_len <= uip_len);

    // Define unconstrained flag:

    uint8_t flag;

    uip_process(flag);
}
