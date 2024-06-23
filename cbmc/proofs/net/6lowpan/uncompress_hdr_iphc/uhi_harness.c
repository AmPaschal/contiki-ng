/**
 * @file uhi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harnesses the uncompress_hdr_iphc function
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/packetbuf.h" 
#include "net/ipv6/sicslowpan.h"

extern uint8_t *packetbuf_ptr;
extern uint8_t packetbuf_hdr_len;
extern int packetbuf_payload_len;
extern uint8_t *packetbuf;

void harness() {

    // Ensure packet pointer is not NULL:

    __CPROVER_assume(packetbuf != NULL);

    // Ensure memory is valid:

    __CPROVER_assume(__CPROVER_rw_ok(packetbuf, PACKETBUF_SIZE));

    // Define out buffer size:

    uint16_t outb_size;

    // Create out buffer:
    // (Buffer won't be NULL)

    uint8_t* outb = (uint8_t*)malloc(sizeof(uint8_t) * outb_size);

    __CPROVER_assume(outb != NULL);

    // Define size of in buffer:

    uint16_t inb_size;

    // The in buffer must be greater than out buffer:

    __CPROVER_assume(inb_size >= outb_size);

    // Allocate data:

    const uint8_t *tdata = (uint8_t *)malloc(sizeof(uint8_t) * inb_size);

    // Ensure data is not NULL:

    __CPROVER_assume(tdata != NULL);

    // Copy data into packetbuf:

    uint16_t datalen = packetbuf_copyfrom(tdata, inb_size);

    // Set data pointer:

    packetbuf_ptr = packetbuf_hdrptr();

    // Pointer won't be null:

    __CPROVER_assume(packetbuf_ptr != NULL);

    // Pointer will be valid:

    __CPROVER_assume(__CPROVER_rw_ok(packetbuf_ptr, datalen));

    // Define header and data size:

    __CPROVER_assume(packetbuf_payload_len >= 0);
    __CPROVER_assume(packetbuf_hdr_len + packetbuf_payload_len <= datalen);

    // Define IP length:

    uint16_t ip_legnth;

    uipbuf_clear();
    
    // Init 6LowPAN

    sicslowpan_init();

    uncompress_hdr_iphc(outb, outb_size, ip_legnth);
}
