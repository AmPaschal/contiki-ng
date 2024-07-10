/**
 * @file dio_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for dio_input
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include "net/routing/rpl-lite/rpl.h"
#include "net/routing/rpl-lite/rpl-icmp6.h"

extern uint16_t uip_len;
uint16_t uip_ext_len; // Define header extension length

void harness() {

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Total length of extension headers will not exceed buffer size:

    __CPROVER_assume(uip_l3_icmp_hdr_len <= uip_len);

    dio_input();
}
