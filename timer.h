#ifndef __TIMER__
#define __TIMER__

#include <stdio.h>
#include <time.h>

//constantes
#define COUNTING 1
#define RESETED 0
#define STOPPED 2


int timer_begin_counting();

int timer_stop_counting();

int timer_reset();

#endif