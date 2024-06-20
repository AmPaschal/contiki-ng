/**
 * @file mde_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for snmp message decoding
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-message.h"

#include "snmp-generic.h"

void harness() {

    // Create packet to be processed:

    snmp_packet_t pack;

    // Initialize:

    //init_packet_in(&pack);

    pack.used = 200;
    pack.in = malloc(pack.used);

    __CPROVER_assume(pack.in != NULL);

    // Create header:

    snmp_header_t header;

    // Determine varbind array size:
    // (TODO: Make unconstrained to test large varbind sizes?)

    const uint32_t vsize = SNMP_MAX_NR_VALUES;

    // Create varbind array:

    snmp_varbind_t varbinds[2];

    // Pass values to function:

    snmp_message_decode(&pack, &header, varbinds);
}
