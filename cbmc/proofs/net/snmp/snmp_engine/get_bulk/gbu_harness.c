/**
 * @file gbu_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for get_bulk function
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-engine.h"

void harness() {

    // Create header:

    snmp_header_t header;

    // Create varbind array:

    snmp_varbind_t varbinds[5];

    // Send along to function:

    snmp_engine_get_bulk(&header, varbinds);
}
