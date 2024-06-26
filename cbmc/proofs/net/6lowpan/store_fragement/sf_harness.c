/**
 * @file sf_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for store_fragment
 * @version 0.1
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/sicslowpan.h"

#include "gnet/packetbuf-generic.h"

extern uint8_t *packetbuf_ptr;
extern uint8_t packetbuf_hdr_len;
extern int packetbuf_payload_len;

void harness() {

    // Initialize packetbuf:

    uint16_t datalen = init_packetbuf();

    // Define unconstrained values for index and offset:

    uint8_t index;
    uint8_t offset;

    // Set data pointer:

    packetbuf_ptr = packetbuf_hdrptr();

    // Pointer won't be null:

    __CPROVER_assume(packetbuf_ptr != NULL);

    // Pointer will be valid:

    __CPROVER_assume(__CPROVER_rw_ok(packetbuf_ptr, datalen));

    // Define header and data size:

    __CPROVER_assume(packetbuf_payload_len >= 0);
    __CPROVER_assume((packetbuf_hdr_len) + packetbuf_payload_len < datalen);

    sicslowpan_init();

    store_fragment(index, offset);
}
