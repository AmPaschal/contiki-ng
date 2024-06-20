/**
 * @file uhi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harnesses the uncompress_hdr_iphc function
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/sicslowpan.h"

void harness() {

    // Define out buffer size:

    uint16_t outb_size;

    // Create out buffer:
    // (Buffer won't be NULL)

    uint8_t outb = (uint8_t*)malloc(sizeof(uint8_t) * outb_size);

    __CPROVER_assume(outb != NULL);

    // Define IP length:

    uint16_t ip_legnth;

    uncompress_hdr_iphc(outb, outb_size, ip_legnth);
}
