#include "pwm.h"
#include "pinAccess.h" //PORTA
#include "pinMux.h"    //pinMux
#include "timer.h"     //TCinitClock
#include "sam.h"	   //TC3

void ledPwmInit()
{
	pinMux(PORTA,15,CONFIG_E);
	TCinitClock(F48MHZ,3);
	//prescaler 4, mode pwm, mode 8 bits.
	TC3->COUNT8.CTRLA.reg = 2 <<8 | 2 << 5 | 1 << 2;
	//46KHz
	TC3->COUNT8.PER.reg = 254; 
	TC3->COUNT8.CC[1].reg = 255; //ratio 0% => éteinte
	TC3->COUNT8.CTRLA.reg |= 2;
}

void ledPwmSet(unsigned char ratio)
{
	TC3->COUNT8.CC[1].reg = 255-ratio;
}
