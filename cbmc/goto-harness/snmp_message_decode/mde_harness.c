#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

// tag-#anon#ST[*{cS8}'string'|U32'length']
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 181
struct anonymous$1;

// tag-#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 206
struct anonymous$0;

// tag-#anon#UN[U32'integer'|SYM#0={ST[*{cS8}'string'|U32'length']}'string'|SYMsnmp_oid_s#1={ST[ARR16{U32}'data'|U8'length'|U24'$pad2']}'oid']
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 173
union anonymous;

// tag-snmp_header_s
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 93
struct snmp_header_s;

// tag-snmp_msg_community
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 101
struct snmp_msg_community;

// tag-snmp_oid_s
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 144
struct snmp_oid_s;

// tag-snmp_varbind_s
// file ../../../../../../os/net/app-layer/snmp/snmp.h line 159
struct snmp_varbind_s;


typedef struct snmp_header_s snmp_header_t;
typedef struct snmp_oid_s snmp_oid_t;
typedef struct anonymous$0 snmp_packet_t;
typedef struct snmp_varbind_s snmp_varbind_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

// snmp_ber_decode_integer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 261
signed int snmp_ber_decode_integer(snmp_packet_t *, uint32_t *);
// snmp_ber_decode_length
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 250
signed int snmp_ber_decode_length(snmp_packet_t *, uint8_t *);
// snmp_ber_decode_null
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 294
signed int snmp_ber_decode_null(snmp_packet_t *);
// snmp_ber_decode_oid
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 305
signed int snmp_ber_decode_oid(snmp_packet_t *, snmp_oid_t *);
// snmp_ber_decode_string_len_buffer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 284
signed int snmp_ber_decode_string_len_buffer(snmp_packet_t *, const char **, uint32_t *);
// snmp_ber_decode_timeticks
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 272
signed int snmp_ber_decode_timeticks(snmp_packet_t *, uint32_t *);
// snmp_ber_decode_type
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 239
signed int snmp_ber_decode_type(snmp_packet_t *, uint8_t *);
// snmp_ber_encode_integer
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 183
signed int snmp_ber_encode_integer(snmp_packet_t *, uint32_t);
// snmp_ber_encode_length
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 172
signed int snmp_ber_encode_length(snmp_packet_t *, uint16_t);
// snmp_ber_encode_null
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 228
signed int snmp_ber_encode_null(snmp_packet_t *, uint8_t);
// snmp_ber_encode_oid
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 217
signed int snmp_ber_encode_oid(snmp_packet_t *, snmp_oid_t *);
// snmp_ber_encode_string_len
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 206
signed int snmp_ber_encode_string_len(snmp_packet_t *, const char *, uint32_t);
// snmp_ber_encode_timeticks
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 194
signed int snmp_ber_encode_timeticks(snmp_packet_t *, uint32_t);
// snmp_ber_encode_type
// file ../../../../../../os/net/app-layer/snmp/snmp-ber.h line 161
signed int snmp_ber_encode_type(snmp_packet_t *, uint8_t);
// snmp_message_decode
// file ../../../../../../os/net/app-layer/snmp/snmp-message.c line 189
signed int snmp_message_decode(snmp_packet_t *snmp_packet, snmp_header_t *header, snmp_varbind_t *varbinds);
// snmp_message_decode_harness
// 
void snmp_message_decode_harness(void);
// snmp_message_encode
// file ../../../../../../os/net/app-layer/snmp/snmp-message.c line 49
signed int snmp_message_encode(snmp_packet_t *snmp_packet, snmp_header_t *header, snmp_varbind_t *varbinds);
// type_constructor_
// 
void type_constructor_(signed int depth_, union anonymous *result_);
// type_constructor_arr_uint_16
// 
void type_constructor_arr_uint_16(signed int depth_arr_uint_16, uint32_t (*result_arr_uint_16)[16]);
// type_constructor_char
// 
void type_constructor_char(signed int depth_char, char *result_char);
// type_constructor_ptr_char
// 
void type_constructor_ptr_char(signed int depth_ptr_char, const char **result_ptr_char);
// type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// 
void type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](signed int depth_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], snmp_packet_t **result_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']);
// type_constructor_ptr_tag_snmp_header_s
// 
void type_constructor_ptr_tag_snmp_header_s(signed int depth_ptr_tag_snmp_header_s, snmp_header_t **result_ptr_tag_snmp_header_s);
// type_constructor_ptr_tag_snmp_varbind_s
// 
void type_constructor_ptr_tag_snmp_varbind_s(signed int depth_ptr_tag_snmp_varbind_s, snmp_varbind_t **result_ptr_tag_snmp_varbind_s);
// type_constructor_ptr_uint
// 
void type_constructor_ptr_uint(signed int depth_ptr_uint, uint8_t **result_ptr_uint);
// type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// 
void type_constructor_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](signed int depth_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'], snmp_packet_t *result_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']);
// type_constructor_tag_snmp_header_s
// 
void type_constructor_tag_snmp_header_s(signed int depth_tag_snmp_header_s, snmp_header_t *result_tag_snmp_header_s);
// type_constructor_tag_snmp_msg_community
// 
void type_constructor_tag_snmp_msg_community(signed int depth_tag_snmp_msg_community, struct snmp_msg_community *result_tag_snmp_msg_community);
// type_constructor_tag_snmp_oid_s
// 
void type_constructor_tag_snmp_oid_s(signed int depth_tag_snmp_oid_s, snmp_oid_t *result_tag_snmp_oid_s);
// type_constructor_tag_snmp_varbind_s
// 
void type_constructor_tag_snmp_varbind_s(signed int depth_tag_snmp_varbind_s, snmp_varbind_t *result_tag_snmp_varbind_s);
// type_constructor_uint
// 
void type_constructor_uint(signed int depth_uint, uint16_t *result_uint);
// type_constructor_uint_0
// 
void type_constructor_uint_0(signed int depth_uint$0, uint8_t *result_uint$0);
// type_constructor_uint_1
// 
void type_constructor_uint_1(signed int depth_uint$1, uint32_t *result_uint$1);

struct anonymous$1
{
  // string
  const char *string;
  // length
  uint32_t length;
};

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

typedef struct snmp_oid_s
{
  // data
  uint32_t data[16];
  // length
  uint8_t length;
} snmp_oid_t;

union anonymous
{
  // integer
  uint32_t integer;
  // string
  struct { const char *string; uint32_t length; } string;
  // oid
  snmp_oid_t oid;
};

struct snmp_msg_community
{
  // community
  const char *community;
  // length
  uint32_t length;
};

struct snmp_header_s
{
  // version
  uint32_t version;
  // community
  struct snmp_msg_community community;
  // pdu_type
  uint8_t pdu_type;
  // request_id
  uint32_t request_id;
  // error_status
  uint32_t error_status;
  // non_repeaters
  uint32_t non_repeaters;
  // error_index
  uint32_t error_index;
  // max_repetitions
  uint32_t max_repetitions;
};

struct snmp_varbind_s
{
  // oid
  snmp_oid_t oid;
  // value_type
  uint8_t value_type;
  // value
  union { uint32_t integer; struct anonymous$1 string; snmp_oid_t oid; } value;
};


// __GOTO_HARNESS::has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']
// file __GOTO_HARNESSharness.c
signed int has_seen_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out']=0;
// __GOTO_HARNESS::has_seen_tag_snmp_header_s
// file __GOTO_HARNESSharness.c
signed int has_seen_tag_snmp_header_s=0;
// __GOTO_HARNESS::has_seen_tag_snmp_varbind_s
// file __GOTO_HARNESSharness.c
signed int has_seen_tag_snmp_varbind_s=0;
// __GOTO_HARNESS::max_depth
// file __GOTO_HARNESSharness.c
signed int max_depth=2;
// __GOTO_HARNESS::min_depth
// file __GOTO_HARNESSharness.c
signed int min_depth=1;
// curr_log_level_snmp
// file ../../../../../../os/sys/log.h line 118
extern signed int curr_log_level_snmp;

// snmp_message_decode_harness
// 
void snmp_message_decode_harness(void)
{
  snmp_packet_t *snmp_packet;
  snmp_header_t *header;
  snmp_varbind_t *varbinds;
  type_constructor_ptr_tag_#anon#ST[U16'used'|U16'max'|*{U8}'in'|*{U8}'out'](0, &snmp_packet);
  type_constructor_ptr_tag_snmp_header_s(0, &header);
  type_constructor_ptr_tag_snmp_varbind_s(0, &varbinds);
  snmp_message_decode(snmp_packet, header, varbinds);
  free(snmp_packet);
  free(header);
  free(varbinds);
}

// type_constructor_
// 
void type_constructor_(signed int depth_, union anonymous *result_)
{
  union anonymous nondet$3;
  *result_ = nondet$3;
}

// type_constructor_arr_uint_16
// 
void type_constructor_arr_uint_16(signed int depth_arr_uint_16, uint32_t (*result_arr_uint_16)[16])
{
  type_constructor_uint_1(depth_arr_uint_16, *result_arr_uint_16);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[1u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[2u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[3u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[4u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[5u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[6u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[7u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[8u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[9u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[10u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[11u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[12u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[13u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[14u]);
  type_constructor_uint_1(depth_arr_uint_16, &(*result_arr_uint_16)[15u]);
}

// type_constructor_char
// 
void type_constructor_char(signed int depth_char, char *result_char)
{
  char nondet$2;
  *result_char = nondet$2;
}

// type_constructor_ptr_char
// 
void type_constructor_ptr_char(signed int depth_ptr_char, const char **result_ptr_char)
{
  if(depth_ptr_char >= max_depth)
    *result_ptr_char = ((const char *)NULL);

  else
  {
    __CPROVER_bool should_recurse_nondet$2;
    if(!(depth_ptr_char >= min_depth) || should_recurse_nondet$2)
    {
      char *local_result$2=malloc(1u);
      type_constructor_char(depth_ptr_char + 1, &(*local_result$2));
      *result_ptr_char = local_result$2;
    }

    else
      *result_ptr_char = ((const char *)NULL);
  }
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

// type_constructor_ptr_tag_snmp_header_s
// 
void type_constructor_ptr_tag_snmp_header_s(signed int depth_ptr_tag_snmp_header_s, snmp_header_t **result_ptr_tag_snmp_header_s)
{
  if(depth_ptr_tag_snmp_header_s >= max_depth && has_seen_tag_snmp_header_s == 1)
    *result_ptr_tag_snmp_header_s = ((snmp_header_t *)NULL);

  else
  {
    __CPROVER_bool should_recurse_nondet$1;
    if(!(depth_ptr_tag_snmp_header_s >= min_depth) || should_recurse_nondet$1)
    {
      signed int has_seen_prev_tag_snmp_header_s=has_seen_tag_snmp_header_s;
      has_seen_tag_snmp_header_s = 1;
      snmp_header_t *local_result$1=malloc(36u);
      type_constructor_tag_snmp_header_s(depth_ptr_tag_snmp_header_s + 1, &(*local_result$1));
      *result_ptr_tag_snmp_header_s = local_result$1;
      has_seen_tag_snmp_header_s = has_seen_prev_tag_snmp_header_s;
    }

    else
      *result_ptr_tag_snmp_header_s = ((snmp_header_t *)NULL);
  }
}

// type_constructor_ptr_tag_snmp_varbind_s
// 
void type_constructor_ptr_tag_snmp_varbind_s(signed int depth_ptr_tag_snmp_varbind_s, snmp_varbind_t **result_ptr_tag_snmp_varbind_s)
{
  if(depth_ptr_tag_snmp_varbind_s >= max_depth && has_seen_tag_snmp_varbind_s == 1)
    *result_ptr_tag_snmp_varbind_s = ((snmp_varbind_t *)NULL);

  else
  {
    __CPROVER_bool should_recurse_nondet$3;
    if(!(depth_ptr_tag_snmp_varbind_s >= min_depth) || should_recurse_nondet$3)
    {
      signed int has_seen_prev_tag_snmp_varbind_s=has_seen_tag_snmp_varbind_s;
      has_seen_tag_snmp_varbind_s = 1;
      snmp_varbind_t *local_result$3=malloc(140u);
      type_constructor_tag_snmp_varbind_s(depth_ptr_tag_snmp_varbind_s + 1, &(*local_result$3));
      *result_ptr_tag_snmp_varbind_s = local_result$3;
      has_seen_tag_snmp_varbind_s = has_seen_prev_tag_snmp_varbind_s;
    }

    else
      *result_ptr_tag_snmp_varbind_s = ((snmp_varbind_t *)NULL);
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

// type_constructor_tag_snmp_header_s
// 
void type_constructor_tag_snmp_header_s(signed int depth_tag_snmp_header_s, snmp_header_t *result_tag_snmp_header_s)
{
  type_constructor_uint_1(depth_tag_snmp_header_s, &result_tag_snmp_header_s->version);
  type_constructor_tag_snmp_msg_community(depth_tag_snmp_header_s, &result_tag_snmp_header_s->community);
  type_constructor_uint_0(depth_tag_snmp_header_s, &result_tag_snmp_header_s->pdu_type);
  type_constructor_uint_1(depth_tag_snmp_header_s, &result_tag_snmp_header_s->request_id);
  type_constructor_uint_1(depth_tag_snmp_header_s, &result_tag_snmp_header_s->error_status);
  type_constructor_uint_1(depth_tag_snmp_header_s, &result_tag_snmp_header_s->non_repeaters);
  type_constructor_uint_1(depth_tag_snmp_header_s, &result_tag_snmp_header_s->error_index);
  type_constructor_uint_1(depth_tag_snmp_header_s, &result_tag_snmp_header_s->max_repetitions);
}

// type_constructor_tag_snmp_msg_community
// 
void type_constructor_tag_snmp_msg_community(signed int depth_tag_snmp_msg_community, struct snmp_msg_community *result_tag_snmp_msg_community)
{
  type_constructor_ptr_char(depth_tag_snmp_msg_community, &result_tag_snmp_msg_community->community);
  type_constructor_uint_1(depth_tag_snmp_msg_community, &result_tag_snmp_msg_community->length);
}

// type_constructor_tag_snmp_oid_s
// 
void type_constructor_tag_snmp_oid_s(signed int depth_tag_snmp_oid_s, snmp_oid_t *result_tag_snmp_oid_s)
{
  type_constructor_arr_uint_16(depth_tag_snmp_oid_s, &result_tag_snmp_oid_s->data);
  type_constructor_uint_0(depth_tag_snmp_oid_s, &result_tag_snmp_oid_s->length);
}

// type_constructor_tag_snmp_varbind_s
// 
void type_constructor_tag_snmp_varbind_s(signed int depth_tag_snmp_varbind_s, snmp_varbind_t *result_tag_snmp_varbind_s)
{
  type_constructor_tag_snmp_oid_s(depth_tag_snmp_varbind_s, &result_tag_snmp_varbind_s->oid);
  type_constructor_uint_0(depth_tag_snmp_varbind_s, &result_tag_snmp_varbind_s->value_type);
  type_constructor_(depth_tag_snmp_varbind_s, &result_tag_snmp_varbind_s->value);
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

// type_constructor_uint_1
// 
void type_constructor_uint_1(signed int depth_uint$1, uint32_t *result_uint$1)
{
  uint32_t nondet$1;
  *result_uint$1 = nondet$1;
}

