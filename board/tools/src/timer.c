#include "sam.h"
#include "timer.h"
#include "clock.h"

int TCinitClock(int source, int timerId)
{
	int result = 0;
	if((source > 4) ||(timerId > 7)) result = 1;
	else {
		//arguments Ok.
		//1: Power Management
		PM->APBCMASK.reg |= 1<<(timerId+8);
	
		//2: Clock source
		const static int timerToCLkId[] = {0x1A,0x1A,0x1B,0x1B,0x1C,0x1C,0x1D,0x1D};
		GCLK->CLKCTRL.reg = 1 <<14 | //enable
							source << 8 | //generator
							timerToCLkId[timerId];
	}
	return result;
}

void TC6Reset()
{
	TC6->COUNT16.COUNT.reg = 0;
	TC6->COUNT16.INTFLAG.reg = 1; //raz OVF;
}

void TC6Init()
{
	TCinitClock(F48MHZ,6);
	TC6Reset();
	TC6->COUNT16.CTRLA.reg = 2; //enable, no prescaler, 16 bits
}

int TC6Value(int *result)
{
	*result = TC6->COUNT16.COUNT.reg;
	return (TC6->COUNT16.INTFLAG.reg & 1);
}

