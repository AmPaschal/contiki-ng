/**
 * @file gca_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for get_channel_for_addr
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/mac/ble/ble-l2cap.h"

#include "gnet/packetbuf-generic.h"
#include "l2cap-struct.h"

void harness() {

    // Unconstrained link:

    linkaddr_t link;

    l2cap_channel_t * thing = get_channel_for_addr(&link);

    if (thing != NULL) {
        // Read some data:

        uint16_t cid = thing->channel_own.cid;
    }
}
