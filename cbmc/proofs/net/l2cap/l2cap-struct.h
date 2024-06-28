/**
 * @file l2cap_struct.h
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief General structs used throughout l2cap
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 * Many of the structs used by internal l2cap functions
 * are private and only accessible in the l2cap source file.
 * 
 * This header provides some of these structs to prevent repetition. 
 */

#include "contiki.h"
#include "net/mac/ble/ble-l2cap.h"
#include "net/linkaddr.h"

typedef struct {
  /* L2CAP Service Data Unit (SDU) (= packet data)*/
  uint8_t sdu[BLE_L2CAP_NODE_MTU];
  /* length of the L2CAP SDU */
  uint16_t sdu_length;
  /* index of the first byte not sent yet */
  uint16_t current_index;
} l2cap_buffer_t;

typedef struct {
  uint16_t cid;
  uint16_t mtu;
  uint16_t mps;
  uint16_t credits;
} ble_mac_l2cap_channel_t;

typedef struct {
  ble_mac_l2cap_channel_t channel_own;
  ble_mac_l2cap_channel_t channel_peer;
  l2cap_buffer_t tx_buffer;
  l2cap_buffer_t rx_buffer;
  linkaddr_t peer_addr;
} l2cap_channel_t;
