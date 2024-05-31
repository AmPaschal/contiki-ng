#include "contiki.h"
#include "net/app-layer/snmp/snmp-engine.h"
#include "net/app-layer/snmp/snmp-ber.h"
#include "net/ipv6/uipopt.h"
#include "net/ipv6/uip.h"

/**
 * Decoder method stubs
 * 
 * These methods take way too long to compute
 * and can lead to excessive memory usage.
 * We are stubbing them to return unconstrained values. 
 * 
 */

static inline int snmp_ber_decode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t expected_type, uint32_t *num) {

    // Ensure provided points are not NULL:

    __CPROVER_assert(snmp_packet != NULL, "Provided packet can't be NULL");
    __CPROVER_assert(num != NULL, "Provided value pointer can't be NULL");

    // Some sanity checks, may be removed later:

    uint8_t type, len;

    if(!snmp_ber_decode_type(snmp_packet, &type)) {
        return 0;
    }

    if(type != expected_type) {
        /*
        * Sanity check
        * Invalid type in buffer
        */
        return 0;
    }

    if(!snmp_ber_decode_length(snmp_packet, &len)) {
        return 0;
    }

    if(len > 4) {
        /*
        * Sanity check
        * It will not fit in the uint32_t
        */
        return 0;
    }

    if(snmp_packet->used == 0) {
        return 0;
    }

    if (snmp_packet->used - len < 0) {
        return 0;
    }

    // Define a unconstrained int value:

    uint32_t val;

    // Set value:

    *num = val;

    // Alter pointer and used value:

    snmp_packet->used -= len;
    snmp_packet->in += len;

    return 1;
}

int snmp_ber_decode_string_len_buffer(snmp_packet_t *snmp_packet, const char **str, uint32_t *length) {

    // Ensure provided pointers are not NULL

    __CPROVER_assert(snmp_packet != NULL, "Provided packet can't be NULL");
    __CPROVER_assert(str != NULL, "Provided string can't be NULL");
    __CPROVER_assert(length != NULL, "Provided length pointer can't be NULL");

    // Ensure decoded type is valid:

    uint8_t type;

    if(!snmp_ber_decode_type(snmp_packet, &type)) {
        return 0;
    }

    if(type != BER_DATA_TYPE_OCTET_STRING) {
        /*
        * Sanity check
        * Invalid type in buffer
        */
        return 0;
    }

    // Choose an unconstrained size:

    uint32_t size;

    // Set length to size:

    *length = size;

    // Generate a string of size:

    *str = (char*)malloc(sizeof(char) * size);

    // Alter packet to match size changes:

    snmp_packet->in += size;
    snmp_packet->used -= size;

    return 1;
}

int snmp_ber_decode_integer(snmp_packet_t *snmp_packet, uint32_t *num)
{
  return snmp_ber_decode_unsigned_integer(snmp_packet, BER_DATA_TYPE_INTEGER, num);
}

int snmp_ber_decode_length(snmp_packet_t *snmp_packet, uint8_t *length)
{
  if(snmp_packet->used == 0) {
    return 0;
  }

  *length = *snmp_packet->in++;
  snmp_packet->used--;

  return 1;
}

int snmp_ber_decode_type(snmp_packet_t *snmp_packet, uint8_t *type)
{
  if(snmp_packet->used == 0) {
    return 0;
  }

  *type = *snmp_packet->in++;
  snmp_packet->used--;

  return 1;
}

void harness() {

    // Create a packet:

    snmp_packet_t pack;

    // Define max size of packet:
    pack.max = UIP_BUFSIZE - UIP_IPUDPH_LEN;

    // In size, unconstrained
    uint16_t insize;

    // Ensure size does not exceed max size:

    __CPROVER_assume(insize <= pack.max);

    // Set used to input size:

    pack.used = insize;

    // TODO: Maybe have different sizes for in and out?
    // Would that be realistic or fair?

    // Allocate memory for in data:
    pack.in = (uint8_t*)malloc(sizeof(uint8_t) * insize);

    // Allocate memory for out data:
    pack.out = (uint8_t*)malloc(sizeof(uint8_t) * insize);

    // Allocated memory should not be null:

    __CPROVER_assume(pack.in != NULL);
    __CPROVER_assume(pack.out != NULL);

    // Pass to engine:

    snmp_engine(&pack);
}
