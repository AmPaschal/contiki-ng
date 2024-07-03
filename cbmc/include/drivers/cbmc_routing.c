/**
 * @file cbmc_routing.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief A routing driver for CBMC
 * @version 0.1
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 * This file defines components for a routing driver that
 * is completely unconstrained, 
 * allowing to CMBC to properly model the routing driver.
 */

#include "net/routing/routing.h"

/*---------------------------------------------------------------------------*/
static void
init(void)
{
}
/*---------------------------------------------------------------------------*/
static void
root_set_prefix(uip_ipaddr_t *prefix, uip_ipaddr_t *iid)
{
}
/*---------------------------------------------------------------------------*/
static int
root_start(void)
{
    int blah;

    return blah;
}
/*---------------------------------------------------------------------------*/
static int
node_is_root(void)
{
    int blah;

    return blah;
}
/*---------------------------------------------------------------------------*/
static int
get_root_ipaddr(uip_ipaddr_t *ipaddr)
{
    int blah;

    return blah;
}
/*---------------------------------------------------------------------------*/
static int
get_sr_node_ipaddr(uip_ipaddr_t *addr, const uip_sr_node_t *node)
{
    int blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static void
leave_network(void)
{
}
/*---------------------------------------------------------------------------*/
static int
node_has_joined(void)
{
    int blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static int
node_is_reachable(void)
{
    int blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static void
global_repair(const char *str)
{
}
/*---------------------------------------------------------------------------*/
static void
local_repair(const char *str)
{
}
/*---------------------------------------------------------------------------*/
static bool
ext_header_remove(void)
{
    bool blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static int
ext_header_update(void)
{
    int blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static int
ext_header_hbh_update(uint8_t *ext_buf, int opt_offset)
{
    int blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static int
ext_header_srh_update(void)
{
    int blah;
    return blah; /* Means SRH not found */
}
/*---------------------------------------------------------------------------*/
static int
ext_header_srh_get_next_hop(uip_ipaddr_t *ipaddr)
{
    int blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
static void
link_callback(const linkaddr_t *addr, int status, int numtx)
{
}
/*---------------------------------------------------------------------------*/
static void
neighbor_state_changed(uip_ds6_nbr_t *nbr)
{
}
/*---------------------------------------------------------------------------*/
static void
drop_route(uip_ds6_route_t *route)
{
}
/*---------------------------------------------------------------------------*/
static uint8_t
is_in_leaf_mode(void)
{
    uint8_t blah;
    return blah;
}
/*---------------------------------------------------------------------------*/
const struct routing_driver cbmcrouting_driver = {
    "cbmcrouting",
    init,
    root_set_prefix,
    root_start,
    node_is_root,
    get_root_ipaddr,
    get_sr_node_ipaddr,
    leave_network,
    node_has_joined,
    node_is_reachable,
    global_repair,
    local_repair,
    ext_header_remove,
    ext_header_update,
    ext_header_hbh_update,
    ext_header_srh_update,
    ext_header_srh_get_next_hop,
    link_callback,
    neighbor_state_changed,
    drop_route,
    is_in_leaf_mode,
};
/*---------------------------------------------------------------------------*/

/** @}*/
