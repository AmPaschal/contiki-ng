/**
 * @file input_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for 6LowPAN input function
 * @version 0.1
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/sicslowpan.h"

#include "gnet/packetbuf-generic.h"
#include "drivers/cbmc_sniffer.h"

// int8_t
// add_fragment(uint16_t tag, uint16_t frag_size, uint8_t offset) {}

bool
uncompress_hdr_iphc(uint8_t *buf, uint16_t buf_size, uint16_t ip_len) {}

// int
// clear_fragments(uint8_t frag_info_index) {}

// bool
// copy_frags2uip(int context) {}

void harness() {

    // Init the packetbuf:

    init_packetbuf();

    // Init the system:

    sicslowpan_init();

    // Define the sniffer:

    netstack_sniffer_add(&cbmc_sniffer);

    // Call the input function:

    input();
}
