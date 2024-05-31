#include "contiki.h"
#include "net/app-layer/snmp/snmp-engine.h"

void harness() {

    // Create a packet:

    snmp_packet_t pack;

    // Pass to engine:

    snmp_engine(&pack);
}
