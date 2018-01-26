#ifndef __PWM_H__
#define __PWM_H__

//LED3 => PA15 => TC3/WO[1]

//init Led 3 en mode PWM. Led éteinte.
//~46KHz
void ledPwmInit();

//rapport cyclique de la PWM, entre 0 (0%) et 255 (100%).
void ledPwmSet(unsigned char ratio);

#endif
