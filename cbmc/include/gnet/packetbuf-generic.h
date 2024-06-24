/**
 * @file packetbuf-generic.h
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Generic tools for initializing packetbuf
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 * This header contains methods for initializing packetbuf components,
 * and ensuring these components are in a valid state.
 * If not preformed, you may see errors related to invalid pointers and bad memory segments.
 */

#include "contiki.h"
#include "net/packetbuf.h"

/// Link in packetbuf pointer (static keyword removed!)
extern uint8_t packetbuf[PACKETBUF_SIZE];

/**
 * @brief Initializes the packetbuf pointer
 * 
 * We preform the following:
 * - Ensure packetbuf pointer is not NULL
 * - Ensure packetbuf pointer is readable and writable for maximum size
 * - Write unbounded contents to packetbuf - will not exceed max size
 * 
 * This function does not preform any operations on the pointer,
 * it only asks CBMC to make some sane assumptions about the packetbuf pointer.
 * 
 * We return the size of the data in the packetbuf.
 */
uint16_t init_packetbuf() {

    // Ensure packet pointer is not NULL:

    __CPROVER_assume(packetbuf != NULL);

    // Ensure memory is valid:

    __CPROVER_assume(__CPROVER_rw_ok(packetbuf, PACKETBUF_SIZE));

    // Determine size of data to write:

    const uint16_t psize;

    // Ensure size does not exceed max:

    __CPROVER_assume(psize <= PACKETBUF_SIZE);

    // Allocate data:

    uint8_t *tdata = (uint8_t *)malloc(sizeof(uint8_t) * psize);

    // Ensure data is not NULL:

    __CPROVER_assume(tdata != NULL);

    // Ensure data is valid:

    __CPROVER_assume(__CPROVER_rw_ok(tdata, psize));

    // Copy data into packetbuf:

    packetbuf_copyfrom(tdata, psize);

    // Ensure packet pointer is not NULL:

    __CPROVER_assume(packetbuf != NULL);

    // Ensure memory is valid:

    __CPROVER_assume(__CPROVER_rw_ok(packetbuf, PACKETBUF_SIZE));

    return psize;
}
