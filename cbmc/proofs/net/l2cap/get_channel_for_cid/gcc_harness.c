/**
 * @file gcc_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for get_channel_for_cid
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

    // Define unconstrained CID:

    uint16_t cid;

    l2cap_channel_t* chan = get_channel_for_cid(cid);

    if (chan != NULL) {

        // Access some aspect of this channel:

        uint16_t tc = chan->channel_own.cid;
    }
}
