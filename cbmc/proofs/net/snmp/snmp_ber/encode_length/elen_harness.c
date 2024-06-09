/**
 * @file elen_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests for length encoding
 * @version 0.1
 * @date 2024-06-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

int harness() {

    // First, create packet to be processed:
    snmp_packet_t pack;

    // Initialize:

    init_packet_out(&pack);

    // Define unconstrained size:

    uint16_t size;

    // Pass to function:

    snmp_ber_encode_length(&pack, size);
}
