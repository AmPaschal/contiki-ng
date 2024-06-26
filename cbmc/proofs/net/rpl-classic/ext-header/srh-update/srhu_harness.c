/**
 * @file srhu_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for rpl_ext_header_srh_update
 * @version 0.1
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include "net/routing/rpl-classic/rpl.h"
#include "net/routing/rpl-classic/rpl-conf.h"

extern uint16_t uip_len;
extern uip_buf_t uip_aligned_buf;

void harness() {

    // Ensure uip_len does not exceed UIP_BUFFSIZE:
    // TODO: Uncomment if testing found vulnerability!

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Allocate data:

    uint8_t* data = (uint8_t*)malloc(sizeof(uint8_t) * uip_len);

    memcpy(uip_aligned_buf.u8, data, uip_len);

    rpl_ext_header_srh_update();
}
