/**
 * @file dst_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests string len buffer decoder
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

void harness() {

    // Create a packet:

    snmp_packet_t pack;

    // Initialize:

    init_packet_in(&pack);

    // Define string to pass:

    char* str;

    // Define length value:

    uint32_t length;

    // Pass to string len function:

    snmp_ber_decode_string_len_buffer(&pack, &str, &length);
}
