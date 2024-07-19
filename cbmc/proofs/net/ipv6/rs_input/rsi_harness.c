/**
 * @file rsi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for rs_input
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip-nd6.h"
#include "net/ipv6/uip-ds6-nbr.h"

// Header length
uint16_t uip_ext_len;

// Length of payload data
uint16_t uip_len;

uip_ds6_nbr_t *
uip_ds6_nbr_lookup(const uip_ipaddr_t *ipaddr) {

    bool thing;

    if (thing) {
        return NULL;
    }

    // Allocate an NBR type:
    // (May be NULL)

    uip_ds6_nbr_t* nbrt = (uip_ds6_nbr_t*)malloc(sizeof(uip_ds6_nbr_t));

    // IP address will match:

    nbrt->ipaddr = *ipaddr;

    return nbrt;
}

int
uip_ds6_nbr_rm(uip_ds6_nbr_t *nbr) {

    // Determine if we are NULL:

    if (nbr != NULL) {

        // Assume success:

        return 1;
    }

    return 0;
}

uip_ds6_nbr_t *
uip_ds6_nbr_add(const uip_ipaddr_t *ipaddr, const uip_lladdr_t *lladdr,
                uint8_t isrouter, uint8_t state, nbr_table_reason_t reason,
                void *data) {

    bool thing;

    if (thing) {
        return NULL;
    }

    // Allocate NBR table entry:

    uip_ds6_nbr_t *nbr = (uip_ds6_nbr_t*)malloc(sizeof(uip_ds6_nbr_t));

    // IP address MUST be the same as provided:

    nbr->ipaddr = *ipaddr;

    // Return entry:

    return nbr;
}

const uip_lladdr_t *
uip_ds6_nbr_get_ll(const uip_ds6_nbr_t *nbr) {

    // Allocate lladdr:

    uip_lladdr_t* addr = (uip_lladdr_t*)malloc(sizeof(uip_lladdr_t));

    return addr;
}

void harness() {

    // Payload length will not exceed maximum:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Header length will not exceed size:

    __CPROVER_assume(uip_ext_len <= uip_len - UIP_IPH_LEN);

    rs_input();
}
