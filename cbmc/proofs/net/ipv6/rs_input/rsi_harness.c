/**
 * @file rsi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for rs_input
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip-nd6.h"

// Header length
uint16_t uip_ext_len;

// Length of payload data
uint16_t uip_len;

void harness() {

    // Payload length will not exceed maximum:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Header length will not exceed size:

    __CPROVER_assume(uip_ext_len <= uip_len - UIP_IPH_LEN);

    // Difference between extension header size and buffer size
    // Will not be less than the size of the cast struct

    __CPROVER_assume(uip_len - uip_ext_len - UIP_IPH_LEN >= sizeof(struct uip_tcp_hdr));

    rs_input();
}
