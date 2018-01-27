#include "connections.h"
#undef READY
#include "sam.h"
#include <pinAccess.h>
#include "motorSubsystem.h"

static int32_t gPosition = 0;
static uint8_t gDirection = 0;

void setDir(uint8_t inDir)
{
	gDirection = inDir;
	digitalWrite(pinDirection, inDir);
}

uint8_t direction()
{
	return gDirection;
}

TASK(motorTask)
{
	digitalWrite(pinStep, 1);
	for (volatile int i = 0; i < 10; i++);
	digitalWrite(pinStep, 0);
	if (gDirection == 0) {
		gPosition++;
	}
	else {
		gPosition--;
	}
	TerminateTask();
}

void startMotor()
{
	SetRelAlarm(motorRun, 1, 1);
}

void stopMotor()
{
	CancelAlarm(motorRun);
}

void resetPosition()
{
	gPosition = 0;
}

int32_t position()
{
	return gPosition;
}
