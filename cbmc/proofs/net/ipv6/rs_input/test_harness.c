#include <stdio.h>
#include <string.h>

// #anon_enum$NBR_TABLE_REASON_UNDEFINED=0$NBR_TABLE_REASON_RPL_DIO=1$NBR_TABLE_REASON_RPL_DAO=2$NBR_TABLE_REASON_RPL_DIS=3$NBR_TABLE_REASON_ROUTE=4$NBR_TABLE_REASON_IPV6_ND=5$NBR_TABLE_REASON_MAC=6$NBR_TABLE_REASON_LLSEC=7$NBR_TABLE_REASON_LINK_STATS=8$NBR_TABLE_REASON_IPV6_ND_AUTOFILL=9$NBR_TABLE_REASON_SIXTOP=A
// file ../../../../../os/net/nbr-table.h line 42
enum anonymous { NBR_TABLE_REASON_UNDEFINED=0, NBR_TABLE_REASON_RPL_DIO=1, NBR_TABLE_REASON_RPL_DAO=2, NBR_TABLE_REASON_RPL_DIS=3, NBR_TABLE_REASON_ROUTE=4, NBR_TABLE_REASON_IPV6_ND=5, NBR_TABLE_REASON_MAC=6, NBR_TABLE_REASON_LLSEC=7, NBR_TABLE_REASON_LINK_STATS=8, NBR_TABLE_REASON_IPV6_ND_AUTOFILL=9, NBR_TABLE_REASON_SIXTOP=10 };

// tag-#anon#UN[ARR320{U32}'u32'|ARR1280{U8}'u8']
// file ../../../../../os/net/ipv6/uip.h line 457
union anonymous$0;

// tag-ctimer
// file ../../../../../os/sys/ctimer.h line 63
struct ctimer;

// tag-etimer
// file ../../../../../os/sys/etimer.h line 79
struct etimer;

// tag-process
// file ../../../../../os/sys/process.h line 316
struct process;

// tag-pt
// file ../../../../../os/sys/pt.h line 219
struct pt;

// tag-stimer
// file ../../../../../os/sys/stimer.h line 83
struct stimer;

// tag-timer
// file ../../../../../os/sys/timer.h line 84
struct timer;

// tag-uip_802154_longaddr
// file ../../../../../os/net/ipv6/uip.h line 116
struct uip_802154_longaddr;

// tag-uip_ds6_aaddr
// file ../../../../../os/net/ipv6/uip-ds6.h line 219
struct uip_ds6_aaddr;

// tag-uip_ds6_addr
// file ../../../../../os/net/ipv6/uip-ds6.h line 205
struct uip_ds6_addr;

// tag-uip_ds6_maddr
// file ../../../../../os/net/ipv6/uip-ds6.h line 225
struct uip_ds6_maddr;

// tag-uip_ds6_nbr
// file ../../../../../os/net/ipv6/uip-ds6-nbr.h line 105
struct uip_ds6_nbr;

// tag-uip_ds6_netif
// file ../../../../../os/net/ipv6/uip-ds6.h line 231
struct uip_ds6_netif;

// tag-uip_ds6_prefix
// file ../../../../../os/net/ipv6/uip-ds6.h line 185
struct uip_ds6_prefix;

// tag-uip_icmp6_input_handler
// file ../../../../../os/net/ipv6/uip-icmp6.h line 179
struct uip_icmp6_input_handler;

// tag-uip_icmp_hdr
// file ../../../../../os/net/ipv6/uip.h line 1650
struct uip_icmp_hdr;

// tag-uip_ip6addr_t
// file ../../../../../os/net/ipv6/uip.h line 100
union uip_ip6addr_t;

// tag-uip_ip_hdr
// file ../../../../../os/net/ipv6/uipbuf.h line 37
struct uip_ip_hdr;

// tag-uip_nd6_na
// file ../../../../../os/net/ipv6/uip-nd6.h line 278
struct uip_nd6_na;

// tag-uip_nd6_ns
// file ../../../../../os/net/ipv6/uip-nd6.h line 268
struct uip_nd6_ns;

// tag-uip_nd6_opt_hdr
// file ../../../../../os/net/ipv6/uip-nd6.h line 324
struct uip_nd6_opt_hdr;

// tag-uip_nd6_opt_mtu
// file ../../../../../os/net/ipv6/uip-nd6.h line 342
struct uip_nd6_opt_mtu;

// tag-uip_nd6_opt_prefix_info
// file ../../../../../os/net/ipv6/uip-nd6.h line 330
struct uip_nd6_opt_prefix_info;

// tag-uip_nd6_ra
// file ../../../../../os/net/ipv6/uip-nd6.h line 298
struct uip_nd6_ra;

// tag-uip_packetqueue_handle
// file ../../../../../os/net/ipv6/uip-packetqueue.h line 9
struct uip_packetqueue_handle;

// tag-uip_packetqueue_packet
// file ../../../../../os/net/ipv6/uip-packetqueue.h line 11
struct uip_packetqueue_packet;


typedef unsigned long long int clock_time_t;
typedef unsigned short int lc_t;
typedef enum anonymous nbr_table_reason_t;
typedef void *process_data_t;
typedef unsigned char process_event_t;
typedef unsigned int size_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef union anonymous$0 uip_buf_t;
typedef struct uip_ds6_aaddr uip_ds6_aaddr_t;
typedef struct uip_ds6_addr uip_ds6_addr_t;
typedef struct uip_ds6_maddr uip_ds6_maddr_t;
typedef struct uip_ds6_nbr uip_ds6_nbr_t;
typedef struct uip_ds6_netif uip_ds6_netif_t;
typedef struct uip_ds6_prefix uip_ds6_prefix_t;
typedef struct uip_icmp6_input_handler uip_icmp6_input_handler_t;
typedef union uip_ip6addr_t uip_ip6addr_t;
typedef union uip_ip6addr_t uip_ipaddr_t;
typedef struct uip_802154_longaddr uip_lladdr_t;
typedef struct uip_nd6_na uip_nd6_na;
typedef struct uip_nd6_ns uip_nd6_ns;
typedef struct uip_nd6_opt_hdr uip_nd6_opt_hdr;
typedef struct uip_nd6_opt_mtu uip_nd6_opt_mtu;
typedef struct uip_nd6_opt_prefix_info uip_nd6_opt_prefix_info;
typedef struct uip_nd6_ra uip_nd6_ra;

// harness
// 
void harness(void);
// log_6addr
// file ../../../../../os/sys/log.h line 244
void log_6addr(const uip_ipaddr_t *);
// log_6addr_compact
// file ../../../../../os/sys/log.h line 250
void log_6addr_compact(const uip_ipaddr_t *);
// rs_input
// file ../../../../../os/net/ipv6/uip-nd6.c line 607
void rs_input(void);
// uip_ds6_addr_lookup
// file ../../../../../os/net/ipv6/uip-ds6.h line 324
uip_ds6_addr_t * uip_ds6_addr_lookup(uip_ipaddr_t *);
// uip_ds6_nbr_add
// file ../../../../../os/net/ipv6/uip-ds6-nbr.h line 140
uip_ds6_nbr_t * uip_ds6_nbr_add(const uip_ipaddr_t *, const uip_lladdr_t *, uint8_t, uint8_t, nbr_table_reason_t, void *);
// uip_ds6_nbr_get_ll
// file ../../../../../os/net/ipv6/uip-ds6-nbr.h line 157
const uip_lladdr_t * uip_ds6_nbr_get_ll(const uip_ds6_nbr_t *);
// uip_ds6_nbr_lookup
// file ../../../../../os/net/ipv6/uip-ds6-nbr.h line 198
uip_ds6_nbr_t * uip_ds6_nbr_lookup(const uip_ipaddr_t *);
// uip_ds6_nbr_rm
// file ../../../../../os/net/ipv6/uip-ds6-nbr.h line 150
signed int uip_ds6_nbr_rm(uip_ds6_nbr_t *);
// uip_ds6_nbr_update_ll
// file ../../../../../os/net/ipv6/uip-ds6-nbr.h line 173
signed int uip_ds6_nbr_update_ll(uip_ds6_nbr_t **, const uip_lladdr_t *);
// uip_ds6_select_src
// file ../../../../../os/net/ipv6/uip-ds6.h line 365
void uip_ds6_select_src(uip_ipaddr_t *, uip_ipaddr_t *);
// uip_ds6_send_ra_sollicited
// file ../../../../../os/net/ipv6/uip-ds6.h line 370
void uip_ds6_send_ra_sollicited(void);
// uip_htonl
// file ../../../../../os/net/ipv6/uip.h line 1182
uint32_t uip_htonl(uint32_t);
// uip_htons
// file ../../../../../os/net/ipv6/uip.h line 1175
uint16_t uip_htons(uint16_t);
// uip_icmp6_register_input_handler
// file ../../../../../os/net/ipv6/uip-icmp6.h line 231
void uip_icmp6_register_input_handler(uip_icmp6_input_handler_t *);
// uip_icmp6chksum
// file ../../../../../os/net/ipv6/uip.h line 2012
uint16_t uip_icmp6chksum(void);
// uip_nd6_init
// file ../../../../../os/net/ipv6/uip-nd6.c line 1108
void uip_nd6_init(void);
// uip_nd6_ra_output
// file ../../../../../os/net/ipv6/uip-nd6.c line 703
void uip_nd6_ra_output(const uip_ipaddr_t *dest);
// uipbuf_clear
// file ../../../../../os/net/ipv6/uipbuf.h line 42
void uipbuf_clear(void);
// uipbuf_set_len
// file ../../../../../os/net/ipv6/uipbuf.h line 56
_Bool uipbuf_set_len(uint16_t);
// uipbuf_set_len_field
// file ../../../../../os/net/ipv6/uipbuf.h line 63
void uipbuf_set_len_field(struct uip_ip_hdr *, uint16_t);

union anonymous$0
{
  // u32
  uint32_t u32[320];
  // u8
  uint8_t u8[1280];
};

struct timer
{
  // start
  clock_time_t start;
  // interval
  clock_time_t interval;
};

struct etimer
{
  // timer
  struct timer timer;
  // next
  struct etimer *next;
  // p
  struct process *p;
};

struct ctimer
{
  // next
  struct ctimer *next;
  // etimer
  struct etimer etimer;
  // p
  struct process *p;
  // f
  void (*f)(void *);
  // ptr
  void *ptr;
};

struct pt
{
  // lc
  lc_t lc;
};

struct process
{
  // next
  struct process *next;
  // name
  const char *name;
  // thread
  char (*thread)(struct pt *, process_event_t, process_data_t);
  // pt
  struct pt pt;
  // state
  uint8_t state;
  // needspoll
  _Bool needspoll;
};

struct stimer
{
  // start
  unsigned long int start;
  // interval
  unsigned long int interval;
};

struct uip_802154_longaddr
{
  // addr
  uint8_t addr[8];
};

typedef union uip_ip6addr_t
{
  // u8
  uint8_t u8[16];
  // u16
  uint16_t u16[8];
} uip_ipaddr_t;

struct uip_ds6_aaddr
{
  // ipaddr
  uip_ipaddr_t ipaddr;
  // isused
  uint8_t isused;
};

struct uip_ds6_addr
{
  // ipaddr
  uip_ipaddr_t ipaddr;
  // isused
  uint8_t isused;
  // state
  uint8_t state;
  // type
  uint8_t type;
  // isinfinite
  uint8_t isinfinite;
  // vlifetime
  struct stimer vlifetime;
};

struct uip_ds6_maddr
{
  // ipaddr
  uip_ipaddr_t ipaddr;
  // isused
  uint8_t isused;
};

struct uip_packetqueue_handle
{
  // packet
  struct uip_packetqueue_packet *packet;
};

struct uip_ds6_nbr
{
  // ipaddr
  uip_ipaddr_t ipaddr;
  // isrouter
  uint8_t isrouter;
  // state
  uint8_t state;
  // reachable
  struct stimer reachable;
  // sendns
  struct stimer sendns;
  // nscount
  uint8_t nscount;
  // packethandle
  struct uip_packetqueue_handle packethandle;
};

struct uip_ds6_netif
{
  // link_mtu
  uint32_t link_mtu;
  // base_reachable_time
  uint32_t base_reachable_time;
  // reachable_time
  uint32_t reachable_time;
  // retrans_timer
  uint32_t retrans_timer;
  // addr_list
  uip_ds6_addr_t addr_list[3];
  // aaddr_list
  uip_ds6_aaddr_t aaddr_list[2];
  // maddr_list
  uip_ds6_maddr_t maddr_list[7];
  // cur_hop_limit
  uint8_t cur_hop_limit;
  // maxdadns
  uint8_t maxdadns;
};

struct uip_ds6_prefix
{
  // ipaddr
  uip_ipaddr_t ipaddr;
  // isused
  uint8_t isused;
  // length
  uint8_t length;
  // advertise
  uint8_t advertise;
  // l_a_reserved
  uint8_t l_a_reserved;
  // vlifetime
  uint32_t vlifetime;
  // plifetime
  uint32_t plifetime;
};

struct uip_icmp6_input_handler
{
  // next
  struct uip_icmp6_input_handler *next;
  // handler
  void (*handler)(void);
  // type
  uint8_t type;
  // icode
  uint8_t icode;
};

struct uip_icmp_hdr
{
  // type
  uint8_t type;
  // icode
  uint8_t icode;
  // icmpchksum
  uint16_t icmpchksum;
};

struct uip_ip_hdr
{
  // vtc
  uint8_t vtc;
  // tcflow
  uint8_t tcflow;
  // flow
  uint16_t flow;
  // len
  uint8_t len[2];
  // proto
  uint8_t proto;
  // ttl
  uint8_t ttl;
  // srcipaddr
  uip_ip6addr_t srcipaddr;
  // destipaddr
  uip_ip6addr_t destipaddr;
};

struct uip_nd6_na
{
  // flagsreserved
  uint8_t flagsreserved;
  // reserved
  uint8_t reserved[3];
  // tgtipaddr
  uip_ipaddr_t tgtipaddr;
};

struct uip_nd6_ns
{
  // reserved
  uint32_t reserved;
  // tgtipaddr
  uip_ipaddr_t tgtipaddr;
};

struct uip_nd6_opt_hdr
{
  // type
  uint8_t type;
  // len
  uint8_t len;
};

struct uip_nd6_opt_mtu
{
  // type
  uint8_t type;
  // len
  uint8_t len;
  // reserved
  uint16_t reserved;
  // mtu
  uint32_t mtu;
};

struct uip_nd6_opt_prefix_info
{
  // type
  uint8_t type;
  // len
  uint8_t len;
  // preflen
  uint8_t preflen;
  // flagsreserved1
  uint8_t flagsreserved1;
  // validlt
  uint32_t validlt;
  // preferredlt
  uint32_t preferredlt;
  // reserved2
  uint32_t reserved2;
  // prefix
  uip_ipaddr_t prefix;
};

struct uip_nd6_ra
{
  // cur_ttl
  uint8_t cur_ttl;
  // flags_reserved
  uint8_t flags_reserved;
  // router_lifetime
  uint16_t router_lifetime;
  // reachable_time
  uint32_t reachable_time;
  // retrans_timer
  uint32_t retrans_timer;
};

struct uip_packetqueue_packet
{
  // queue_buf
  uint8_t queue_buf[1280];
  // queue_buf_len
  uint16_t queue_buf_len;
  // lifetimer
  struct ctimer lifetimer;
};


// __GOTO_HARNESS::max_depth
// file __GOTO_HARNESSharness.c
signed int max_depth=2;
// __GOTO_HARNESS::min_depth
// file __GOTO_HARNESSharness.c
signed int min_depth=1;
// curr_log_level_ipv6
// file ../../../../../os/sys/log.h line 111
extern signed int curr_log_level_ipv6;
// uip_aligned_buf
// file ../../../../../os/net/ipv6/uip.h line 462
extern uip_buf_t uip_aligned_buf;
// uip_ds6_if
// file ../../../../../os/net/ipv6/uip-ds6.h line 257
extern uip_ds6_netif_t uip_ds6_if;
// uip_ds6_prefix_list
// file ../../../../../os/net/ipv6/uip-ds6.h line 261
extern uip_ds6_prefix_t uip_ds6_prefix_list[3];
// uip_ext_len
// file ../../../../../os/net/ipv6/uip.h line 1237
extern uint16_t uip_ext_len;
// uip_len
// file ../../../../../os/net/ipv6/uip.h line 1232
extern uint16_t uip_len;
// uip_lladdr
// file ../../../../../os/net/ipv6/uip.h line 1728
extern uip_lladdr_t uip_lladdr;

// harness
// 
void harness(void)
{
  rs_input();
}

