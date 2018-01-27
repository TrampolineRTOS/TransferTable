#include "controller.h"
#include "connections.h"
#include "motorSubsystem.h"
#include "endStopSubsystem.h"
#undef READY
#include "sam.h"
#include <pinAccess.h>
#include "button.h"

static enum { START, ZERO, MANUAL, AUTO, MOVE } mode = START;

const char *modeName[] = {
	"START ", "ZERO  ", "MANUAL", "AUTO  ", "MOVE  "
};

const char * currentMode()
{
	return modeName[mode];
}

static int32_t gSlot = 0;
static int32_t gTarget = 20000;

int32_t slot()
{
	return gSlot;
}

uint8_t allowedToMove()
{
	if (direction() == grayDir && grayEndStop() == 0) {
		return 0;
	}
	else if (direction() == redDir && redEndStop() == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

TASK(controllerTask)
{
	button_state moveButton = readButton(&button1);
	button_state directionButton = readButton(&button2);
	button_state goButton = readButton(&button3);
	button_state modeButton = readButton(&sw0);
	
	switch (mode) {
		case START:
		    if (redEndStop() == 1) {
				setDir(redDir);
				startMotor();
			}
			mode = ZERO;
			break;
		case ZERO:
			if (redEndStop() == 0) {
			  stopMotor();
			  resetPosition();
			  mode = MANUAL;
			}
			break;
		case MANUAL:
			if (allowedToMove()) {
				if (moveButton == ON) {
					startMotor();
				}
				else {
					stopMotor();
				}
			}
			else {
				stopMotor();
			}
			
			if (directionButton == PRESS) {
				setDir(! direction());
			}
			
			if (modeButton == PRESS) {
			  mode = AUTO;
			}
			break;
		case AUTO:
		    if (directionButton == PRESS) {
		      gSlot++;
		      if (gSlot == 3) gSlot = 0;
		    }
		    if (goButton == PRESS) {
		      gTarget = (gSlot + 1) * 20000;
		      if (gTarget > position()) {
		      	setDir(grayDir);
		      }
		      else {
		      	setDir(redDir);
		      }
		      startMotor();
		      mode = MOVE;
		    }
			if (modeButton == PRESS) {
			  mode = MANUAL;
			}
		    break;
		case MOVE:
			if (direction() == grayDir) {
				if (position() >= gTarget) {
					stopMotor();
					mode = AUTO;
				}
			}
			else {
				if (position() <= gTarget) {
					stopMotor();
					mode = AUTO;
				}
			}				
		    break;
	}
		
	TerminateTask();
}