#include "tpl_os.h"
#include "endStopSubsystem.h"
#include "oled.h"

char *state[] = { "ON ", "OFF" };

TASK(display)
{
	OLEDSetTextCursor(0, 0);
	OLEDPrintString("RED EndStop:  ");
	OLEDPrintString(state[redEndStop()]);

	OLEDSetTextCursor(0, 1);
	OLEDPrintString("GRAY EndStop: ");
	OLEDPrintString(state[grayEndStop()]);
	
	TerminateTask();
}