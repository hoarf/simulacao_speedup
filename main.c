#include "timer.h"

int main(int argc, char const *argv[])
{
	int  i;
	timer_reset();
	timer_begin_counting();
	for (i = 0; i < 1000000; ++i)
		printf("%d", i);	
	timer_stop_counting();
	return 0;
}