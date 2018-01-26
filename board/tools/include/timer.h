#ifndef __TIMER_H__
#define __TIMER_H__

//definition des sources d'horloge.
#include "clock.h"

//initialise la source d'horloge du timer 
//(ainsi que son alimentation).
// ***Attention: les timer n (pair) et n+1 (impair) ont
//               forcément la même source d'horloge!
// * TimerId: 0 à 7 (TC3 à TC7 notamment)
// * source: une des 4 fréquences ci-dessus
int TCinitClock(int source, int timerId);

// initialise et démarre le free running timer TC6.
// - timer 16 bits
// - 48 ticks / us => overflow au bout de 1.3 ms
// - remet à 0 le timer.
void TC6Init();

// remet à 0 le timer (et reinitialise la bascule Overflow).
void TC6Reset();

// fonction pour obtenir la valeur du timer:
// - valeur retournée à 0 si pas d'overflow
// - nombre de ticks dans la variable 'result'. Non valide s'il y a un overflow.
//   passage par addresse!
int TC6Value(int *result);

#endif
