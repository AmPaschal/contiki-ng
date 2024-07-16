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
uint16_t uip_ext_len;

void harness2() {

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Extension headers will not exceed buffer size:

    __CPROVER_assume(uip_l3_icmp_hdr_len <= uip_len);

    dio_input();
}

// Link in a global variable in use

extern uint8_t gvar;

// Stub a complicated function

int comp_func() {}

void harness() {

    // Model input argument

    uint8_t inp;

    __CPROVER_assume(inp <= 100);

    // Model global variable

    __CPROVER_assume(gvar >= 200);

    // Call harnessed function

    harnessed_function(inp);
}

