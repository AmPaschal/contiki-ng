/**
 * @file cf2u_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for copy_frags2uip
 * @version 0.1
 * @date 2024-08-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "contiki.h"
#include "net/ipv6/sicslowpan.h"

void harness() {

    // Define unconstrained context:

    int context;

    // Ensure context does not exceed maximum:
    // (2 by default)

    __CPROVER_assume(context < 2);
    __CPROVER_assume(context >= 0);

    // Call function:

    copy_frags2uip(context);
}
