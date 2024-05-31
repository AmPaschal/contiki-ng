#include "contiki.h"
#include "net/packetbuf.h"

void harness() {

    // Define length, unconstrained:
    uint16_t length;

    // Define char array of length:

    char arr[length];

    // Send values to function:

    packetbuf_copyfrom(arr, length);
}
