/**
 * @file doid_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests for the OID decoder
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

div_t div (int __numer, int __denom) {

    // Create unconstrained div type:

    div_t dtype;

    return dtype;
}

void harness() {

    // Create packet:

    snmp_packet_t pack;

    // Initialize packet:

    init_packet_in(&pack);

    // Create OID struct

    snmp_oid_t oid;

    // Set length to be zero
    // TODO: Remove this when re-introducing vulnerability!

    oid.length = 0;

    // Send to function:

    snmp_ber_decode_oid(&pack, &oid);
}
