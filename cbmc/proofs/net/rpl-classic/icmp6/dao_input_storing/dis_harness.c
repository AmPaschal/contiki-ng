/**
 * @file dis_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for dao_input_storing
 * @version 0.1
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include "net/routing/rpl-classic/rpl.h"
#include "net/routing/rpl-classic/rpl-conf.h"

#include "gnet/packetbuf-generic.h"

extern uint16_t uip_len;
uint16_t uip_ext_len;  // Define header extension length

rpl_instance_t *
rpl_get_instance(uint8_t instance_id) {

    // Allocate struct:

    rpl_instance_t* inst = (rpl_instance_t*)malloc(sizeof(rpl_instance_t));

    // Won't be null:

    __CPROVER_assume(inst != NULL);

    // Will be valid for size:

    __CPROVER_assume(__CPROVER_rw_ok(inst, sizeof(rpl_instance_t)));

    // Create DAG:

    rpl_dag_t* dag = (rpl_dag_t*)malloc(sizeof(rpl_dag_t));

    // Won't be NULL:

    __CPROVER_assume(dag != NULL);

    // Will be valid for size:

    __CPROVER_assume(__CPROVER_rw_ok(dag, sizeof(dag)));

    // Set dag and instance pointers:

    inst->current_dag = dag;
    dag->instance = inst;

    return inst;
}

rpl_parent_t *
rpl_find_parent(rpl_dag_t *dag, uip_ipaddr_t *addr) {

    // Allocate parent:

    rpl_parent_t *p = (rpl_parent_t*)malloc(sizeof(rpl_parent_t));

    // Won't be NULL:

    __CPROVER_assume(p != NULL);

    // Will be valid for size:

    __CPROVER_assume(__CPROVER_rw_ok(p, sizeof(rpl_parent_t)));

    return p;
}

uip_ds6_route_t *
uip_ds6_route_lookup(const uip_ipaddr_t *addr) {

    // Allocate data for route:

    uip_ds6_route_t* route = (uip_ds6_route_t*)malloc(sizeof(uip_ds6_route_t));

    // These functions MAY return NULL!

    // Data won't be NULL:

    // __CPROVER_assume(route != NULL);

    // Data will be valid for size:

    // __CPROVER_assume(__CPROVER_rw_ok(route, sizeof(uip_ds6_route_t)));

    return route;
}

uip_ds6_route_t *
rpl_add_route(rpl_dag_t *dag, uip_ipaddr_t *prefix, int prefix_len,
              uip_ipaddr_t *next_hop) {

    // Just create an unconstrained ds6 route:

    return uip_ds6_route_lookup(NULL);
}

const uip_ipaddr_t *
uip_ds6_route_nexthop(uip_ds6_route_t *route) {

    // This function may return NULL:

    uip_ipaddr_t* ipaddr = (uip_ipaddr_t*)malloc(sizeof(uip_ipaddr_t));

    return ipaddr;
}

void harness() {

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Total length of extension headers will not exceed buffer size:

    __CPROVER_assume(uip_ext_len <= uip_len);

    // Prepare packetbuf:

    init_packetbuf();

    dao_input_storing();
}