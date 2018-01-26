#include "tpl_os.h"
#include "endStopSubsystem.h"
#include "connections.h"
#undef READY
#include "sam.h"
#include <pinAccess.h>

uint8_t gGES = 0; /* At init gray endstop is pressed */
uint8_t gRES = 0; /* At init red endstop is pressed */

uint8_t grayEndStop()
{
	return gGES;
}

uint8_t redEndStop()
{
	return gRES;
}

TASK(endStopScan)
{
	gGES = digitalRead(pinGrayEndStop);
	gRES = digitalRead(pinRedEndStop);
	TerminateTask();
}
