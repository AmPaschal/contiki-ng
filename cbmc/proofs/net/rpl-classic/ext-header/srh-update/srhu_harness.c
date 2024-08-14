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

    // Will NEVER occur due to header length being verified
    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    rpl_ext_header_srh_update();
}
