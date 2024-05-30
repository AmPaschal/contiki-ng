#include "contiki.h"
#include "net/packetbuf.h"

#include "dummy_proc.h"

void harness() {

    // Define length, unconstrained:
    uint16_t length;

    // Define char array of length:

    char arr[10];

    // Violate the array:

    char thing = arr[500];

    // Send values to function:

    packetbuf_copyfrom(arr, length);
}
