/**
 * @file snmp-generic.h
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Various functions for SNMP-BER harnesses
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/ipv6/uipopt.h"
#include "net/ipv6/uip.h"

/**
 * @brief Initialises a packet in a standard way
 * 
 * We preform the following steps:
 * - Define packet max size
 * - Set packet size as unconstrained (won't exceed max)
 * - Set used value to match our determined size
 * - Allocate input buffer (won't be null)
 * - Offset points by unconstrained value (won't exceed max)
 * 
 * Simply pass your packet and this function will initialize it as described.
 */
inline void init_packet(snmp_packet_t* pack) {

    // Define the max size:
    pack->max = UIP_BUFSIZE - UIP_IPUDPH_LEN;

    // Determine the size to work with, should not exceed max:
    uint16_t size;

    __CPROVER_assume(size <= pack->max);

    // Set used amount:

    pack->used = size;

    // Allocate input to in buffer:

    pack->in = (uint8_t*)malloc(sizeof(uint8_t) * size);

    // Allocated data should not be null:

    __CPROVER_assume(pack->in != NULL);

    // Move pointers around by some amount (less than size):

    uint16_t offset;

    __CPROVER_assume(offset <= size);

    pack->in += offset;
    pack->used -= offset;
}
