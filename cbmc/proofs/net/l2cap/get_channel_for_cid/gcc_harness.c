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

extern uint8_t l2cap_channel_count;

void harness() {

    // Define unconstrained CID:

    uint16_t cid;

    __CPROVER_assume(l2cap_channel_count <= L2CAP_CHANNELS);

    // get_channel_for_cid(cid);

    uint8_t* chan = get_channel_for_cid(cid);

    if (chan != NULL) {

        // Access some aspect of this channel:

        uint8_t chan_obj = *chan;
    }
}
