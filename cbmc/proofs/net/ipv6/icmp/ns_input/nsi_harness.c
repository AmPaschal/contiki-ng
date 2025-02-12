/**
 * @file nsi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for ICMP ns_input
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip-nd6.h"
#include "net/ipv6/uip-ds6-nbr.h"
#include "net/linkaddr.h"
#include "net/ipv6/uip-ds6.h"

extern uint16_t uip_ext_len = 0;
extern uint16_t uip_len;

uip_ds6_nbr_t* uip_ds6_nbr_lookup(const uip_ipaddr_t *ipaddr) {

    bool blah;

    // Allocate NBR:

    uip_ds6_nbr_t *onbr = (uip_ds6_nbr_t*)malloc(sizeof(uip_ds6_nbr_t));

    // Return NBR:

    return blah ? NULL : onbr;
}

uip_ds6_addr_t * uip_ds6_addr_lookup(uip_ipaddr_t *ipaddr) {

    bool blah;
    

    // Create address:

    uip_ds6_addr_t* addr = (uip_ds6_addr_t*)malloc(sizeof(uip_ds6_aaddr_t));

    return blah ? NULL : addr;
}

const uip_lladdr_t * uip_ds6_nbr_get_ll(const uip_ds6_nbr_t *nbr)
{

    bool blah;

    uip_lladdr_t* ret = (uip_lladdr_t*)malloc(sizeof(uip_lladdr_t));

    return blah ? NULL : ret;
}


void harness() {

    uint8_t ext_len;

    __CPROVER_assume(uip_len < UIP_BUFSIZE);

    __CPROVER_assume(ext_len < uip_len - 84); // 84 is the computed offset and size of the IPv6 + ICMP + ND6 header. It's rough and the value may not be correct
    uip_ext_len = ext_len;

    ns_input();
}
