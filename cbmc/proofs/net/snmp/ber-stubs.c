/**
 * @file ber-stubs.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Simplified stubs for ber functions
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright Copyright (c) 2024
 * 
 * This file contains simplified snmp-ber stubs.
 * These functions only update the pointer and return unconstrained values.
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

inline int snmp_ber_decode_type(snmp_packet_t *snmp_packet, uint8_t *type) {
  if(snmp_packet->used == 0) {
    return 0;
  }

  // Update pointers:

  snmp_packet->in++;
  snmp_packet->used--;

  // Define type to set:

  uint8_t ntype;

  *type = ntype;

  return 1;
}

int snmp_ber_decode_length(snmp_packet_t *snmp_packet, uint8_t *length) {

  // Identical implementation to decode_type:

  return snmp_ber_decode_type(snmp_packet, length);
}

inline int snmp_ber_decode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t expected_type, uint32_t *num)
{
  uint8_t len = 0;
  uint8_t type = 0;

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

  // Update pointers:
  // Original implementation always increments, even if zero:

  snmp_packet->in++;
  snmp_packet->used--;

  // TODO: Need to determine when we are going over max value!
  // If in the section below we go over the bounds then this function may produce a violation

  // Only increment if len is not zero:

  if (len != 0) {

    snmp_packet->in += (len - 1);
    snmp_packet->used -= (len - 1);
  }

  // Define unconstrained int:

  uint32_t nnum;

  *num = nnum;

  // Define unconstrained return:

  uint8_t ret;

  return 1;
}

int snmp_ber_decode_integer(snmp_packet_t *snmp_packet, uint32_t *num) {

  // Decode as unsigned, pass hardcoded type - just like original:

  return snmp_ber_decode_unsigned_integer(snmp_packet, BER_DATA_TYPE_INTEGER, num);
}

int snmp_ber_decode_timeticks(snmp_packet_t *snmp_packet, uint32_t *timeticks) {

  // Another decode as unsigned with hardcode:

  return snmp_ber_decode_unsigned_integer(snmp_packet, BER_DATA_TYPE_TIMETICKS, timeticks);
}

int snmp_ber_decode_null(snmp_packet_t *snmp_packet) {
  if(snmp_packet->used == 0) {
    return 0;
  }

  snmp_packet->in++;
  snmp_packet->used--;

  if(snmp_packet->used == 0) {
    return 0;
  }

  snmp_packet->in++;
  snmp_packet->used--;

  return 1;
}

int snmp_ber_decode_string_len_buffer(snmp_packet_t *snmp_packet, const char **str, uint32_t *length) {
  uint8_t type = 0;

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

  // Are we at the end?

  if (snmp_packet->used == 0) {
    return 0;
  }

  // Determine how much we should move while decoding length:

  uint8_t lsize;

  // Length must be at most 5:

  __CPROVER_assume(lsize <= 5);

  // Determine if we will move past:

  uint8_t offset = 0;

  if (snmp_packet->used < lsize) {

    // Will move past position, set offset:

    offset = lsize - snmp_packet->used;
  }

  // Offset pointers:

  snmp_packet->in += (lsize - offset);
  snmp_packet->used -= (lsize - offset);

  // Determine if we need to quit:

  if (offset) {
    return 0;
  }

  // Point string at memory pointed to:

  *str = (const char *)snmp_packet->in;

  // Determine if we can't continue:

  if(snmp_packet->used == 0 || snmp_packet->used < *length) {
    return 0;
  }

  // Update pointers past string:

  snmp_packet->used -= *length;
  snmp_packet->in += *length;

  return 1;
}

int snmp_ber_decode_oid(snmp_packet_t *snmp_packet, snmp_oid_t *oid) {
  uint8_t type = 0;
  uint8_t len = 0;

  if(!snmp_ber_decode_type(snmp_packet, &type)) {
    return 0;
  }

  if(type != BER_DATA_TYPE_OBJECT_IDENTIFIER) {
    return 0;
  }

  if(!snmp_ber_decode_length(snmp_packet, &len)) {  // Pulls in potentially malicious size 
    return 0;
  }

  if(snmp_packet->used == 0) {
    return 0;
  }

  // Update pointers once

  snmp_packet->used--;
  snmp_packet->in++;

  if (snmp_packet->used == 0) {
    return 0;
  }

  // Determine how big the OID data should be:

  uint8_t osize;

  // Size must not exceed maximum value:

  __CPROVER_assume(osize < SNMP_MSG_OID_MAX_LEN - 2);

  // Determine if we will go beyond bounds:

  uint8_t offset = 0;

  if (snmp_packet->used < osize * 4) {

    // Determine offset to move values:

    offset = (osize * 4) - snmp_packet->used;
  }

  // Offset pointers:
  // Need to multiply by 4 as each loop moves values by 4:

  snmp_packet->in += (osize * 4 - offset);
  snmp_packet->used -= (osize * 4 - offset);

  // Update length:

  oid->length = osize + 2;

  if (offset) {
    return 0;
  }

  return 1;
}
