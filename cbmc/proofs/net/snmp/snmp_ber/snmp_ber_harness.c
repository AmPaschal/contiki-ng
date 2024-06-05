/**
 * @file snmp_ber_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests some snmp-ber decoding functions
 * @version 0.1
 * @date 2024-06-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"
#include "net/ipv6/uipopt.h"
#include "net/ipv6/uip.h"

void harness() {

    // First, create packet to be processed:
    snmp_packet_t pack;

    // Define the max size:
    pack.max = UIP_BUFSIZE - UIP_IPUDPH_LEN;

    // Determine the size to work with, should not exceed max:
    uint16_t size;

    __CPROVER_assume(size <= pack.max);

    // Set used amount:

    pack.used = size;

    // Allocate input to in buffer:

    pack.in = (uint8_t*)malloc(sizeof(uint8_t) * size);

    // Allocated data should not be null:

    __CPROVER_assume(pack.in != NULL);

    // Move pointers around by some amount (less than size):

    uint16_t offset;

    __CPROVER_assume(offset <= size);

    pack.in += offset;
    pack.used -= offset;

    // Define an unconstrained type and output:

    uint8_t type, out;

    snmp_ber_decode_unsigned_integer(&pack, type, &out);
}
