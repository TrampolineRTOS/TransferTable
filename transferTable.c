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
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);
  pinMode(pinButton3, INPUT_PULLUP);
  pinMode(pinSW0, INPUT_PULLUP);
  pinMode(pinDirection, OUTPUT); /* direction of the motor */
  pinMode(pinStep, OUTPUT); /* step to move the motor */
  OLEDInit(0);
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
