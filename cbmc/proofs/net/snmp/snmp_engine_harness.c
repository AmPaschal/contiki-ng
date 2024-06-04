#include "contiki.h"
#include "net/app-layer/snmp/snmp-engine.h"
#include "net/app-layer/snmp/snmp-ber.h"
#include "net/app-layer/snmp/snmp-mib.h"
#include "net/ipv6/uipopt.h"
#include "net/ipv6/uip.h"

#include <stdlib.h>

/**
 * Decoder method stubs
 * 
 * These methods take way too long to compute
 * and can lead to excessive memory usage.
 * We are stubbing them to return unconstrained values. 
 * 
 */

inline int snmp_ber_decode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t expected_type, uint32_t *num) {

    // Ensure provided points are not NULL:

    __CPROVER_assert(snmp_packet != NULL, "Provided packet can't be NULL");
    __CPROVER_assert(num != NULL, "Provided value pointer can't be NULL");

    // Some sanity checks, may be removed later:

    uint8_t type, len;

    if(!snmp_ber_decode_type(snmp_packet, &type)) {
        return 0;
    }

    if(!snmp_ber_decode_length(snmp_packet, &len)) {
        return 0;
    }

    // The length MUST not be greater than 4:

    __CPROVER_assume(len <= 4);

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

    __CPROVER_assume(type == BER_DATA_TYPE_OCTET_STRING);

    // Choose an unconstrained size:

    uint32_t size;

    __CPROVER_assume(size < 100);

    // Set length to size:

    *length = size;

    // Generate a string of size:

    *str = (char*)malloc(sizeof(char) * size);

    // Alter packet to match size changes:

    snmp_packet->in += size;
    snmp_packet->used -= size;

    return 1;
}

int snmp_ber_encode_string_len(snmp_packet_t *snmp_packet, const char *str, uint32_t length)
{

  __CPROVER_assume(snmp_packet != NULL);
  __CPROVER_assume(str != NULL);

  // TODO: We do not copy the string values!
  // Maybe it would be good to preform this operation?
  // The problem is we need to copy the string data backwards into the out data,
  // So that may introduce a complicated loop. 

  // Update pointers to new values:

  snmp_packet->out -= length;
  snmp_packet->used += length;

  // Create some dummy data:

  //uint8_t* ddata = (uint8_t*)malloc(sizeof(uint8_t)*length);

  //__CPROVER_assume(ddata != NULL);

  // Copy the data over:

  //memcpy(snmp_packet->out, ddata, length);

  if(!snmp_ber_encode_length(snmp_packet, length)) {
    return 0;
  }

  if(!snmp_ber_encode_type(snmp_packet, BER_DATA_TYPE_OCTET_STRING)) {
    return 0;
  }

  return 1;
}

int snmp_ber_encode_oid(snmp_packet_t *snmp_packet, snmp_oid_t *oid) {
  
  __CPROVER_assume(snmp_packet != NULL);
  __CPROVER_assume(oid != NULL);

  uint32_t val;
  uint16_t original_out_len;
  uint8_t pos;

  pos = oid->length - 1;

  // Pos contains the amount of things to write,
  // so update the pointers:

  snmp_packet->out -= pos;
  snmp_packet->used += pos;

  // Allocate some data:

  uint8_t* odata = (uint8_t*)malloc(sizeof(uint8_t) * pos);

  __CPROVER_assume(odata != NULL);

  // Copy the data in:

  memcpy(snmp_packet->out, odata, pos);

  if(snmp_packet->used == snmp_packet->max) {
    return 0;
  }

  // We don't know exactly how much to copy,
  // so just let the upper bound be the difference between used and max: 

  int numc;

  __CPROVER_assume(numc < (snmp_packet->max - snmp_packet->used));

  // Create some more dummy data:
  // TODO: Again, data copying is disabled for now

  odata = (uint8_t*)malloc(sizeof(uint8_t)*numc);

  __CPROVER_assume(odata != NULL);

  // Copy data over:

  memcpy(snmp_packet->out, odata, numc);

  // Update pointers again:

  snmp_packet->out -= numc;
  snmp_packet->used += numc;

  if(!snmp_ber_encode_length(snmp_packet, snmp_packet->used - original_out_len)) {
    return 0;
  }

  if(!snmp_ber_encode_type(snmp_packet, BER_DATA_TYPE_OBJECT_IDENTIFIER)) {
    return 0;
  }

  return 1;

}

int snmp_ber_decode_oid(snmp_packet_t *snmp_packet, snmp_oid_t *oid)
{

  __CPROVER_assume(snmp_packet != NULL);
  __CPROVER_assume(oid != NULL);

  uint8_t *buf_end, type;
  uint8_t len;
  div_t first;  // Let first be unconstrained

  if(!snmp_ber_decode_type(snmp_packet, &type)) {
    return 0;
  }

  if(type != BER_DATA_TYPE_OBJECT_IDENTIFIER) {
    return 0;
  }

  if(!snmp_ber_decode_length(snmp_packet, &len)) {
    return 0;
  }

  buf_end = snmp_packet->in + len;

  if(snmp_packet->used == 0) {
    return 0;
  }

  // Update pointers:

  snmp_packet->used--;
  snmp_packet->in++;

  oid->length = 0;

  oid->data[oid->length++] = (uint32_t)first.quot;
  oid->data[oid->length++] = (uint32_t)first.rem;

  // Determine amount of data to write:

  int write = buf_end - snmp_packet->in;

  __CPROVER_assume(write < SNMP_MSG_OID_MAX_LEN);

  // Update values:

  oid->length += write;

  // Allocate some dummy data:

  // uint32_t* ddata = (uint32_t*)malloc(sizeof(uint32_t) * write);

  // __CPROVER_assume(ddata != NULL);

  // Copy data over:

  // memcpy(oid->data, ddata, write);

  snmp_packet->in += write;
  snmp_packet->used -= write;

  return 1;
}

inline int snmp_mib_cmp_oid(snmp_oid_t *oid1, snmp_oid_t *oid2)
{

  // Define value to return, must be 1 or 0:

  int ret;

  __CPROVER_assume(ret == 0 || ret == 1);

  return ret;
}

int snmp_ber_encode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t type, uint32_t number) {

  __CPROVER_assume(snmp_packet != NULL);

  uint16_t original_out_len;

  // Just use unconstrained number:

  uint32_t uout;

  // Define a size to use, MUST not be greater than 32:

  uint8_t size;

  __CPROVER_assume(size <= 32);

  // Move pointers and sizes:

  snmp_packet->out -= size;
  snmp_packet->used += size;

  // TODO: We are not writing any encoded data

  if(!snmp_ber_encode_length(snmp_packet, snmp_packet->used - original_out_len)) {
    return 0;
  }

  if(!snmp_ber_encode_type(snmp_packet, type)) {
    return 0;
  }

  return 1;

}

snmp_mib_resource_t *
snmp_mib_find(snmp_oid_t *oid) {}

snmp_mib_resource_t *
snmp_mib_find_next(snmp_oid_t *oid) {}

int snmp_engine_get_bulk(snmp_header_t *header, snmp_varbind_t *varbinds) {}

void harness() {

  // Create a packet:

  snmp_packet_t pack;

  // Define max size of packet:
  pack.max = UIP_BUFSIZE - UIP_IPUDPH_LEN;

  // In size, unconstrained
  uint16_t insize;

  // Ensure size does not exceed max size:

  __CPROVER_assume(insize <= 10);

  // Set used to input size:

  pack.used = insize;

  // TODO: Maybe have different sizes for in and out?
  // Would that be realistic or fair?

  // Allocate memory for in data:
  pack.in = (uint8_t*)malloc(sizeof(uint8_t) * insize);

  // Allocate memory for out data:
  // I believe the out pointer initially points to last value in input buffer?
  pack.out = pack.in + insize;

  // Allocated memory should not be null:

  __CPROVER_assume(pack.in != NULL);
  __CPROVER_assume(pack.out != NULL);

  // Pass to engine:

  snmp_engine(&pack);
}
