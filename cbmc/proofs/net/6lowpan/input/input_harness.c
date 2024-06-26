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

void harness() {

    // Init the packetbuf:

    init_packetbuf();

    // Init the system:

    sicslowpan_init();

    // Call the input function:

    input();
}
