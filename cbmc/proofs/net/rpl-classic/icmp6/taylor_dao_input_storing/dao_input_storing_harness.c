#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/routing/rpl-classic/rpl.h"


rpl_instance_t *
rpl_get_instance(uint8_t instance_id) {
    //Returns NULL or an entry out of instance table
    bool maybe;
    
    if(maybe) {
        return NULL;
    }

    rpl_instance_t* fake_rpl = malloc(sizeof(rpl_instance_t));
    rpl_dag_t* fake_dag = malloc(sizeof(rpl_dag_t)); // Not sure what the constants on this are
    fake_rpl -> current_dag = fake_dag;
    return fake_rpl;
}

rpl_parent_t *
rpl_find_parent(rpl_dag_t *dag, uip_ipaddr_t *addr)
{
    bool maybe;
    
    if(maybe) {
        return NULL;
    }

    rpl_parent_t* fake_rpl_parent = malloc(sizeof(rpl_parent_t));
    rpl_dag_t* fake_dag = malloc(sizeof(rpl_dag_t)); // Not sure what the constants on this are
    fake_rpl_parent -> dag = fake_dag;
    return fake_rpl_parent;
}

uip_ds6_route_t *
uip_ds6_route_lookup(const uip_ipaddr_t *addr)
{
    bool maybe;
    
    if(maybe) {
        return NULL;
    }

    uip_ds6_route_t * fake_route = malloc(sizeof(uip_ds6_route_t));
    return fake_route;
}

uip_ds6_route_t *
rpl_add_route(rpl_dag_t *dag, uip_ipaddr_t *prefix, int prefix_len,
              uip_ipaddr_t *next_hop)
{
    bool maybe;
    
    if(maybe) {
        return NULL;
    }

    uip_ds6_route_t * fake_route = malloc(sizeof(uip_ds6_route_t));
    return fake_route;
}

int memcmp (const void *__s1, const void *__s2, size_t __n) {
    int rand;
    return rand;
}

void harness() {

    extern uip_buf_t uip_aligned_buf;
    extern uint16_t uip_ext_len;
    extern uint16_t uip_len;

    dao_input_storing();
}