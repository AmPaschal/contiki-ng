#include "contiki.h"

#include <stdio.h>

PROCESS(hello_world_process, "NullNet unicast example");
AUTOSTART_PROCESSES(&hello_world_process);

PROCESS_THREAD(hello_world_process, ev, data)
{

  PROCESS_BEGIN();

  PROCESS_END();
}


void harness() {

    int thing = 1;
    ++thing;
}
