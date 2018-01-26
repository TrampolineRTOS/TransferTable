#include "tpl_os.h"
//the READY tasks state definition conflicts with registers definition (in sam.h)
#undef READY
#include "sam.h"
#include "connections.h"
#include <pinAccess.h>
#include "oled.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(pinRedEndStop, INPUT_PULLUP); /* Red EndStop input */
  pinMode(pinGrayEndStop, INPUT_PULLUP); /* Gray EndStop input */
  OLEDInit(0);
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
