#include "timer.h"

//variaveris de estado
time_t timer_init;
int timer_state;

//metodos privados
int init_timer();
int stop_timer();

int timer_begin_counting() 
{
	switch (timer_state) {
	case COUNTING:
		printf("%s\n","O timer já foi inicializado, use timer_reset() para reiniciá-lo");		
		break;
	case RESETED:
		init_timer();
		break;
	case STOPPED:
		printf("%s\n","O timer já foi inicializado, use timer_stop() para pará-lo");		
		break;
	}
}

int timer_stop_counting()
{
	switch (timer_state) {
	case COUNTING:
		stop_timer();
		break;
	case RESETED:
		printf("%s\n","O timer não foi inicializado");		
		break;
	case STOPPED:
		printf("%s\n","O timer já está parado");		
		break;
	}	
}

int init_timer() 
{
	printf("%s\n","Iniciando o timer. tic tac" );
	timer_state = COUNTING;
	time(&timer_init);	
}

int stop_timer() 
{
	timer_state = STOPPED;
	printf("Timer parado. Levou %2.2f segundos para terminar\n", difftime(time(NULL),timer_init));
}

int timer_reset()
{
	printf("%s\n", "Timer resetado, use timer_begin_counting() para iniciá-lo");
	timer_state = RESETED;
}

