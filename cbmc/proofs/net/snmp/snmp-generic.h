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
 * @brief Initialises a packet in a standard way for decoding
 * 
 * We preform the following steps:
 * - Define packet max size
 * - Set packet size as unconstrained (won't exceed max)
 * - Set used value to match our determined size
 * - Allocate input buffer (won't be null)
 * 
 * Simply pass your packet and this function will initialize it as described.
 */
inline void init_packet_in(snmp_packet_t* pack) {

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
}

/**
 * @brief Initialises a packet in a standard way for encoding
 * 
 * We preform the following steps:
 * - Define packet max size
 * - Set packet size as the maximum size
 * - Set used value to zero
 * - Allocate output buffer (won't be null)
 * 
 * Simply pass your packet and this function will initialize it as described.
 * SNMP encodes in data backwards, so we have to do things in reverse.
 * Also, I believe the SNMP packets assume the max size of the out data to be the max value.
 * As data is written, the used value is is incremented, so the only way the writing functions
 * are able to tell that all data is written is by comparing it with the max value.
 * So, if we set the buffer size to be less than the max,
 * we will see problems SNMP has no way of knowing it is out of bounds.
 */
inline void init_packet_out(snmp_packet_t* pack) {

    // Define the max size:
    pack->max = UIP_BUFSIZE - UIP_IPUDPH_LEN;

    // Determine the size to work with, should not exceed max:
    uint16_t size = pack->max;

    __CPROVER_assume(size <= pack->max);

    // Set used amount:

    pack->used = 0;

    // Allocate input to in buffer:

    pack->out = (uint8_t*)malloc(sizeof(uint8_t) * size);

    // Allocated data should not be null:

    __CPROVER_assume(pack->out != NULL);

    // Move pointer to end (don't do so if zero):

    if (size != 0) {

        pack->out += (size-1);
    }
}

/**
 * @brief Offsets in packet pointers
 * 
 * We offset the in packet data by some amount,
 * and we ensure this amount will not exceed the packet length.
 * This function is primarily useful for snmp-ber functions,
 * where they are expected to decode data at arbitrary positions.
 * 
 * @param pack Packet to offset
 */
void offset_packet_in(snmp_packet_t* pack) {

    // Move pointers around by some amount (less than size):

    uint16_t offset;

    __CPROVER_assume(offset <= pack->used);

    pack->in += offset;
    pack->used -= offset;
}

/**
 * @brief Offsets out packet pointers
 * 
 * We offset the out packet data by some amount.
 * and we ensure this amount will not exceed the packet length.
 * This function is primarily useful for snmp-ber functions,
 * where they are expected to decode data at arbitrary positions.
 * 
 * @param pack Packet to offset
 */
void offset_packet_out(snmp_packet_t* pack) {

    // Move pointers around by some amount (less than size):

    uint16_t offset;

    __CPROVER_assume(offset <= pack->used);

    pack->out -= offset;
    pack->used += offset;
}
