
/** The total length of the IPv6 packet in the sicslowpan_buf. */

/* This needs to be defined in NBR / Nodes depending on available RAM   */
/*   and expected reassembly requirements                               */
#ifdef SICSLOWPAN_CONF_FRAGMENT_BUFFERS
#define SICSLOWPAN_FRAGMENT_BUFFERS SICSLOWPAN_CONF_FRAGMENT_BUFFERS
#else
#define SICSLOWPAN_FRAGMENT_BUFFERS 12
#endif

/* REASS_CONTEXTS corresponds to the number of simultaneous
 * reassemblies that can be made. NOTE: the first buffer for each
 * reassembly is stored in the context since it can be larger than the
 * rest of the fragments due to header compression.
 **/
#ifdef SICSLOWPAN_CONF_REASS_CONTEXTS
#define SICSLOWPAN_REASS_CONTEXTS SICSLOWPAN_CONF_REASS_CONTEXTS
#else
#define SICSLOWPAN_REASS_CONTEXTS 2
#endif

/* The size of each fragment (IP payload) for the 6lowpan fragmentation */
#ifdef SICSLOWPAN_CONF_FRAGMENT_SIZE
#define SICSLOWPAN_FRAGMENT_SIZE SICSLOWPAN_CONF_FRAGMENT_SIZE
#else
/* The default fragment size (110 bytes for 127-2 bytes frames) */
#define SICSLOWPAN_FRAGMENT_SIZE (127 - 2 - 15)
#endif

/* Check the selected fragment size, since we use 8-bit integers to handle it. */
#if SICSLOWPAN_FRAGMENT_SIZE > 255
#error Too large SICSLOWPAN_FRAGMENT_SIZE set.
#endif

/* Assuming that the worst growth for uncompression is 38 bytes */
#define SICSLOWPAN_FIRST_FRAGMENT_SIZE (SICSLOWPAN_FRAGMENT_SIZE + 38)

/* all information needed for reassembly */
struct sicslowpan_frag_info {
  /** When reassembling, the source address of the fragments being merged */
  linkaddr_t sender;
  /** When reassembling, the tag in the fragments being merged. */
  uint16_t tag;
  /** Total length of the fragmented packet */
  uint16_t len;
  /** Current length of reassembled fragments */
  uint16_t reassembled_len;
  /** Reassembly %process %timer. */
  struct timer reass_timer;

  /** Fragment size of first fragment */
  uint16_t first_frag_len;
  /** First fragment - needs a larger buffer since the size is uncompressed size
   and we need to know total size to know when we have received last fragment. */
  uint8_t first_frag[SICSLOWPAN_FIRST_FRAGMENT_SIZE];
};

struct sicslowpan_frag_buf {
  /* the index of the frag_info */
  uint8_t index;
  /* Fragment offset */
  uint8_t offset;
  /* Length of this fragment (if zero this buffer is not allocated) */
  uint8_t len;
  uint8_t data[SICSLOWPAN_FRAGMENT_SIZE];
};