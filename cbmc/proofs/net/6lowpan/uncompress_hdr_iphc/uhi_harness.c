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
#include "net/ipv6/uip.h"

#include "gnet/packetbuf-generic.h"

extern uint8_t *packetbuf_ptr;
extern uint8_t packetbuf_hdr_len;
extern int packetbuf_payload_len;

void harness() {

    // Ensure packetbuf is valid:

    uint16_t datalen = init_packetbuf();

    // Define out buffer size:

    const uint16_t outb_size;

    // The in buffer must be <= out buffer:

    __CPROVER_assume(datalen <= outb_size);
    __CPROVER_assume(outb_size <= UIP_BUFSIZE);
    __CPROVER_assume(outb_size >= sizeof(struct uip_ip_hdr));

    // Create out buffer:
    // (Buffer won't be NULL)

    uint8_t* outb = (uint8_t*)malloc(sizeof(uint8_t) * outb_size);

    __CPROVER_assume(outb != NULL);

    // Set data pointer:

    packetbuf_ptr = packetbuf_hdrptr();

    // Pointer won't be null:

    __CPROVER_assume(packetbuf_ptr != NULL);

    // Pointer will be valid:

    __CPROVER_assume(__CPROVER_rw_ok(packetbuf_ptr, datalen));

    // Define header and data size:

    __CPROVER_assume(packetbuf_payload_len >= 0);
    __CPROVER_assume((packetbuf_hdr_len) + packetbuf_payload_len < datalen);

    // Define IP length:

    uint16_t ip_legnth;
    
    // Init 6LowPAN

    sicslowpan_init();

    uncompress_hdr_iphc(outb, outb_size, ip_legnth);
}
