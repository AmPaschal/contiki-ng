/**
 * @file ua_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for uncompress_addr
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/sicslowpan.h"

// Pointer to data to uncompress
extern uint8_t *iphc_ptr;

void harness() {

    // Define an unconstrained IP6 address:

    uip_ipaddr_t ipaddr;

    // Define unconstrained 802.15.4 address

    uip_lladdr_t lladdr;

    // Define prefix counts variable:

    uint8_t prefix_counts;

    // Get nibbles:

    uint8_t pre = prefix_counts >> 4;  // Upper nibble, prefix size
    uint8_t post = prefix_counts & 0x0f;  // Lower nibble, iphc_pointer size

    // Special case - If counts are are 15, they need to be 16

    if (pre == 15) {
        ++pre;
    }

    if (post == 15) {
        ++post;
    }

    // Allocate prefix array:

    uint8_t const prefix[pre];

    // Allocate source address data:
    // To test vulnerability, make 'post' be unconstrained uint8_t

    iphc_ptr = (uint8_t*)malloc(sizeof(uint8_t) * post);

    // Won't be NULL:

    __CPROVER_assume(iphc_ptr != NULL);

    uncompress_addr(&ipaddr, prefix, prefix_counts, &lladdr);
}
