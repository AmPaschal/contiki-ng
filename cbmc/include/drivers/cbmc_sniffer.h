/**
 * @file cbmc_sniffer.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief CBMC network sniffer driver
 * @version 0.1
 * @date 2024-07-08
 * 
 * @copyright Copyright (c) 2024
 * 
 * This file defines a network sniffer that does nothing.
 * The main use for this is for CBMC harnesses.
 */

#include "net/netstack.h"

static void cbmcs_input_callback() {}

static void cbmcs_output_callback(int mac_status) {}

//
// Define the sniffer
//

const struct netstack_sniffer cbmc_sniffer = {
    NULL,
    cbmcs_input_callback,
    cbmcs_output_callback
};
