#include "tpl_os.h"
#include "endStopSubsystem.h"
#include "motorSubsystem.h"
#include "oled.h"
#include "controller.h"

char *state[] = { "ON ", "OFF" };

TASK(display)
{
	OLEDSetTextCursor(0, 0);
	OLEDPrintString("RES: ");
	OLEDPrintString(state[redEndStop()]);

	OLEDSetTextCursor(0, 1);
	OLEDPrintString("GES: ");
	OLEDPrintString(state[grayEndStop()]);
	
	OLEDSetTextCursor(0, 2);
	OLEDPrintString("MOD: ");
	OLEDPrintString((char *)currentMode());
	
	OLEDSetTextCursor(0, 3);
	OLEDPrintString("POS: ");
	OLEDPrintInt(position(),8);
	
	OLEDSetTextCursor(60, 0);
	if (direction() == 0) {
		OLEDPrintString("towards GRAY");
	}
	else {
        OLEDPrintString("towards RED ");
	} 
	
	TickType dummy;
	OLEDSetTextCursor(60, 1);
	if (GetAlarm(motorRun, &dummy) == E_OK) {
	   	OLEDPrintString("RUN ");
	}
	else {
	   	OLEDPrintString("STOP");
	}	
	
	OLEDSetTextCursor(70, 3);
	OLEDPrintString("SLOT: ");
	OLEDPrintInt(slot(), 1);
	
	TerminateTask();
}