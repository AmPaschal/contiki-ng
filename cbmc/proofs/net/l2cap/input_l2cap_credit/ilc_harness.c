/**
 * @file ilc_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for input_l2cap_credit
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/mac/ble/ble-l2cap.h"

#include "gnet/packetbuf-generic.h"

void harness() {

    // Create packetbuf:

    uint16_t len = init_packetbuf();

    uint8_t *data = (uint8_t *)packetbuf_dataptr();

    input_l2cap_credit(data);
}