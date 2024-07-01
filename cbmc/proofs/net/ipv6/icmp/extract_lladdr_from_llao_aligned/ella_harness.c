/**
 * @file ella_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for ICMP extract_lladdr_from_llao_aligned
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip-nd6.h"

extern uint8_t *nd6_opt_llao;

void harness() {

    // Create unconstrained address:

    uip_lladdr_t addr;

    // Define size (wont exceed 200, bigger than 8)

    uint8_t size;

    __CPROVER_assume(size <= 200 && size >= 10);

    // Allocate data:

    nd6_opt_llao = (uint8_t*)malloc(sizeof(uint8_t) * size);

    int res = extract_lladdr_from_llao_aligned(&addr);
}
