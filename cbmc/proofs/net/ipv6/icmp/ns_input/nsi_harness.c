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

uip_ds6_nbr_t* uip_ds6_nbr_lookup(const uip_ipaddr_t *ipaddr) {

    bool blah;

    if (blah) {
        return NULL;
    }

    // Allocate NBR:

    uip_ds6_nbr_t* onbr = (uip_ds6_nbr_t*)malloc(sizeof(uip_ds6_nbr_t));

    // Return NBR:

    return onbr;
}

int uip_ds6_nbr_update_ll(uip_ds6_nbr_t **nbr_pp, const uip_lladdr_t *new_ll_addr) {

    int thing;

    return thing;
}

uip_ds6_addr_t * uip_ds6_addr_lookup(uip_ipaddr_t *ipaddr) {

    bool blah;

    if (blah) {
        return NULL;
    }

    // Create address:

    uip_ds6_addr_t* addr = (uip_ds6_addr_t*)malloc(sizeof(uip_ds6_aaddr_t));

    return addr;
}

const uip_lladdr_t * uip_ds6_nbr_get_ll(const uip_ds6_nbr_t *nbr)
{

    bool blah;

    if (blah) {
        return NULL;
    }

    uip_lladdr_t* ret = (uip_lladdr_t*)malloc(sizeof(uip_lladdr_t));

    return ret;
}

void harness() {

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Total length of extension headers will not exceed buffer size:

    __CPROVER_assume(uip_ext_len <= uip_len);

    ns_input();
}