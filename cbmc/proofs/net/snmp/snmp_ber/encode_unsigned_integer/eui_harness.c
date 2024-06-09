/**
 * @file eui_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests for unsigned integer encoding
 * @version 0.1
 * @date 2024-06-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

void harness() {

    // First, create packet to be processed:
    snmp_packet_t pack;

    // Initialize:

    init_packet_out(&pack);

    // Define unconstrained values:

    uint8_t type;
    uint32_t number;

    // Encode the unsigned int:

    snmp_ber_encode_unsigned_integer(&pack, type, number);
}
