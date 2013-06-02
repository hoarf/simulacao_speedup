#include "timer.h"

int main(int argc, char const *argv[])
{
	int  i;
	
	//Exemplo de como usar o timer
	timer_reset();
	timer_begin_counting();
	for (i = 0; i < 1000000; ++i)
		printf("%d", i);
		
	//Exemplo de como imprimir o resultado do timer		
	timer_stop_counting();
	return 0;
}
