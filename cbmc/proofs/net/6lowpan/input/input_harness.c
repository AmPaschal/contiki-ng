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
#include "sicslowpan-dummy.h"

// #include "gnet/packetbuf-generic.h"
// #include "drivers/cbmc_sniffer.h"

// int8_t
// add_fragment(uint16_t tag, uint16_t frag_size, uint8_t offset) {}

bool
uncompress_hdr_iphc(uint8_t *buf, uint16_t buf_size, uint16_t ip_len) {}

// int
// clear_fragments(uint8_t frag_info_index) {}

// bool
// copy_frags2uip(int context) {}

struct netstack_sniffer {
  struct netstack_sniffer *next;
  void (*input_callback)(void);
  void (*output_callback)(int mac_status);
};

void input_cb_function(){}

void *memcpy(void *dest, const void *src, size_t n);

extern struct netstack_sniffer *callback;

extern struct sicslowpan_frag_info frag_info[SICSLOWPAN_REASS_CONTEXTS];
extern uint16_t uip_ext_len;
extern struct sicslowpan_frag_buf frag_buf[SICSLOWPAN_FRAGMENT_BUFFERS];

void harness() {

    // Init the packetbuf:

    // init_packetbuf();
    int size;
    __CPROVER_assume(size > 0 && size < 100);
    uint8_t *buf = malloc(size);

    __CPROVER_assume(buf != NULL);

    packetbuf_copyfrom(buf, size);

    // Initialize global variable callback
    callback = malloc(sizeof(struct netstack_sniffer));

    callback->input_callback = input_cb_function;

    int first_frag_len;
    __CPROVER_assume(first_frag_len > 0 && first_frag_len < 48); // 48 because of #define SICSLOWPAN_FIRST_FRAGMENT_SIZE (SICSLOWPAN_FRAGMENT_SIZE + 38)

    frag_info[0].first_frag_len = first_frag_len;
    frag_info[1].first_frag_len = first_frag_len;

    __CPROVER_assume(uip_ext_len == 0);

    // Init the system:

    // sicslowpan_init();

    // Define the sniffer:

    // netstack_sniffer_add(&cbmc_sniffer);

    // Call the input function:

    input();
}
