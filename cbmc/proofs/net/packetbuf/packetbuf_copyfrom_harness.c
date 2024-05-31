#define NETSTACK_CONF_MAC MAC_CONF_WITH_NULLMAC

#include "contiki.h"
#include "net/packetbuf.h"

void harness() {

    // Define length, unconstrained:
    uint16_t length;

    // Define char array of length:

    char arr[length];

    // Violate the array:

    // Send values to function:

    packetbuf_copyfrom(arr, length);
}
