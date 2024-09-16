/**
 * @file dnull_harness.c
 * @author Taylor Le Lievre (tlelievr@purdue.edu)
 * @brief Tests for the decode length function
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

void harness() {

    //Initialize params

    snmp_packet_t havoc_pack;

    int rand_size;
    //Contain malloc size between 1 and 100 bytes
    __CPROVER_assume(rand_size >= 1 && rand_size <= 100);

    // Function never checks if the length can possibly be a null pointer
    // Want to malloc so that CBMC will try passing in NULL values
    // I'm assuming that if you just define a normal int and then pass in the pointer, CBMC won't try a null pointer
    uint8_t* packet_length = malloc(rand_size);

    // Create packet values

    init_packet_in(&havoc_pack);

    //Pretty simple function, no stubs needed
    //As far as I can tell, most of the time this is called with a simple if statement, no constraints on inputs

    snmp_ber_decode_length(&havoc_pack, packet_length);
}
