
#include "contiki.h"

PROCESS(dummy_proc, "Dummy Process Example");
AUTOSTART_PROCESSES(&dummy_proc);

PROCESS_THREAD(dummy_proc, ev, data)
{

  PROCESS_BEGIN();

  PROCESS_END();
}
