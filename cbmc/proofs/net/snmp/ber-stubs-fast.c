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

  // Define type to set:

  uint8_t ntype;

  *type = ntype;

  uint8_t ret;

  __CPROVER_assume(ret == 1 || ret == 0);

  return ret;
}

int snmp_ber_decode_length(snmp_packet_t *snmp_packet, uint8_t *length) {

  // Identical implementation to decode_type:

  return snmp_ber_decode_type(snmp_packet, length);
}

inline int snmp_ber_decode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t expected_type, uint32_t *num)
{
  uint8_t len;

  // Define unconstrained int:

  uint32_t nnum;

  *num = nnum;

  // Define unconstrained return:

  uint8_t ret;

  __CPROVER_assume(ret == 1 || ret == 0);

  return ret;
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

  uint8_t ret;

  __CPROVER_assume(ret == 1 || ret == 0);

  return ret;
}

int snmp_ber_decode_string_len_buffer(snmp_packet_t *snmp_packet, const char **str, uint32_t *length) {

  // Point string at memory pointed to:

  *str = (const char *)snmp_packet->in;

  uint8_t ret;

  __CPROVER_assume(ret == 1 || ret == 0);

  return ret;
}

int snmp_ber_decode_oid(snmp_packet_t *snmp_packet, snmp_oid_t *oid) {

  // Determine how big the OID data should be:

  uint8_t osize;

  // Size must not exceed maximum value:

  __CPROVER_assume(osize < SNMP_MSG_OID_MAX_LEN);

  oid->length = osize;

  uint8_t ret;

  __CPROVER_assume(ret == 1 || ret == 0);

  return ret;
}
