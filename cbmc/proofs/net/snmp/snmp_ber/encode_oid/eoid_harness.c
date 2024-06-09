/**
 * @file eoid_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Test for ODI encoding
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

int harness() {

    // Create the packet:
    snmp_packet_t pack;

    // Initialise:

    init_packet_out(&pack);

    // Create OID structure:

    snmp_oid_t oid;

    // Constrain size to be <= 16:

    __CPROVER_assume(oid.length <= SNMP_MSG_OID_MAX_LEN + 1 && oid.length > 0);

    // Send to function:

    snmp_ber_encode_oid(&pack, &oid);
}
