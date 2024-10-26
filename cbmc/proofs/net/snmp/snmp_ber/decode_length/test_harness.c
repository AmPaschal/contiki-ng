#include <stdlib.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

// tag-#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 206
struct anonymous$0;

// tag-snmp_oid_s
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 144
struct snmp_oid_s;


typedef struct snmp_oid_s snmp_oid_t;
typedef struct anonymous$0 snmp_packet_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

// harness
// 
void harness(void);
// snmp_ber_decode_integer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 360
signed int snmp_ber_decode_integer(snmp_packet_t *snmp_packet, uint32_t *num);
// snmp_ber_decode_length
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 341
signed int snmp_ber_decode_length(snmp_packet_t *snmp_packet, uint8_t *length);
// snmp_ber_decode_null
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 497
signed int snmp_ber_decode_null(snmp_packet_t *snmp_packet);
// snmp_ber_decode_oid
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 435
signed int snmp_ber_decode_oid(snmp_packet_t *snmp_packet, snmp_oid_t *oid);
// snmp_ber_decode_string_len_buffer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 366
signed int snmp_ber_decode_string_len_buffer(snmp_packet_t *snmp_packet, const char **str, uint32_t *length);
// snmp_ber_decode_timeticks
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 354
signed int snmp_ber_decode_timeticks(snmp_packet_t *snmp_packet, uint32_t *timeticks);
// snmp_ber_decode_type
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 328
signed int snmp_ber_decode_type(snmp_packet_t *snmp_packet, uint8_t *type);
// snmp_ber_decode_unsigned_integer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 280
inline signed int snmp_ber_decode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t expected_type, uint32_t *num);
// snmp_ber_encode_integer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 152
signed int snmp_ber_encode_integer(snmp_packet_t *snmp_packet, uint32_t number);
// snmp_ber_encode_length
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 96
signed int snmp_ber_encode_length(snmp_packet_t *snmp_packet, uint16_t length);
// snmp_ber_encode_null
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 266
signed int snmp_ber_encode_null(snmp_packet_t *snmp_packet, uint8_t type);
// snmp_ber_encode_oid
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 186
signed int snmp_ber_encode_oid(snmp_packet_t *snmp_packet, snmp_oid_t *oid);
// snmp_ber_encode_string_len
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 158
signed int snmp_ber_encode_string_len(snmp_packet_t *snmp_packet, const char *str, uint32_t length);
// snmp_ber_encode_timeticks
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 146
signed int snmp_ber_encode_timeticks(snmp_packet_t *snmp_packet, uint32_t timeticks);
// snmp_ber_encode_type
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 83
signed int snmp_ber_encode_type(snmp_packet_t *snmp_packet, uint8_t type);
// snmp_ber_encode_unsigned_integer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.c line 50
inline signed int snmp_ber_encode_unsigned_integer(snmp_packet_t *snmp_packet, uint8_t type, uint32_t number);
// type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// 
void type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](signed int depth_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], snmp_packet_t **result_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']);
// type_constructor_ptr_uint
// 
void type_constructor_ptr_uint(signed int depth_ptr_uint, uint8_t **result_ptr_uint);
// type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// 
void type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](signed int depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], snmp_packet_t *result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']);
// type_constructor_uint
// 
void type_constructor_uint(signed int depth_uint, uint16_t *result_uint);
// type_constructor_uint_0
// 
void type_constructor_uint_0(signed int depth_uint$0, uint8_t *result_uint$0);

struct anonymous$0
{
  // used
  uint16_t used;
  // max
  uint16_t max;
  // in
  uint8_t *in;
  // out
  uint8_t *out;
};

struct snmp_oid_s
{
  // data
  uint32_t data[16];
  // length
  uint8_t length;
};


// __GOTO_HARNESS::has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// file __GOTO_HARNESSharness.c
signed int has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']=0;
// __GOTO_HARNESS::max_depth
// file __GOTO_HARNESSharness.c
signed int max_depth=2;
// __GOTO_HARNESS::min_depth
// file __GOTO_HARNESSharness.c
signed int min_depth=1;

// harness
// 
void harness(void)
{
  snmp_packet_t *snmp_packet;
  uint8_t *length;
  type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](0, &snmp_packet);
  type_constructor_ptr_uint(0, &length);
  snmp_ber_decode_length(snmp_packet, length);
  free(snmp_packet);
  free(length);
}

// type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// 
void type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](signed int depth_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], snmp_packet_t **result_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'])
{
  if(depth_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] >= max_depth && has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] == 1)
    *result_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] = ((snmp_packet_t *)NULL);

  else
  {
    __CPROVER_bool should_recurse_nondet;
    if(!(depth_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] >= min_depth) || should_recurse_nondet)
    {
      signed int has_seen_prev_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']=has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'];
      has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] = 1;
      snmp_packet_t *local_result=malloc(12u);
      type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](depth_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] + 1, &(*local_result));
      *result_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] = local_result;
      has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] = has_seen_prev_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'];
    }

    else
      *result_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'] = ((snmp_packet_t *)NULL);
  }
}

// type_constructor_ptr_uint
// 
void type_constructor_ptr_uint(signed int depth_ptr_uint, uint8_t **result_ptr_uint)
{
  if(depth_ptr_uint >= max_depth)
    *result_ptr_uint = ((uint8_t *)NULL);

  else
  {
    __CPROVER_bool should_recurse_nondet$0;
    if(!(depth_ptr_uint >= min_depth) || should_recurse_nondet$0)
    {
      uint8_t *local_result$0=malloc(1u);
      type_constructor_uint_0(depth_ptr_uint + 1, &(*local_result$0));
      *result_ptr_uint = local_result$0;
    }

    else
      *result_ptr_uint = ((uint8_t *)NULL);
  }
}

// type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// 
void type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](signed int depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], snmp_packet_t *result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'])
{
  type_constructor_uint(depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], &result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']->used);
  type_constructor_uint(depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], &result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']->max);
  type_constructor_ptr_uint(depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], &result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']->in);
  type_constructor_ptr_uint(depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], &result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']->out);
}

// type_constructor_uint
// 
void type_constructor_uint(signed int depth_uint, uint16_t *result_uint)
{
  uint16_t nondet;
  *result_uint = nondet;
}

// type_constructor_uint_0
// 
void type_constructor_uint_0(signed int depth_uint$0, uint8_t *result_uint$0)
{
  uint8_t nondet$0;
  *result_uint$0 = nondet$0;
}

