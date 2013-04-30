#include "timer.h"

//variaveris de estado
time_t timer_init;
int timer_state;

//metodos privados
int initTimer();
int stopTimer();

int timer_begin_counting() 
{
	switch (timer_state) {
	case COUNTING:
		printf("%s\n","O timer já foi inicializado, use timer_reset() para reiniciá-lo");		
		break;
	case RESETED:
		initTimer();
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
		stopTimer();
		break;
	case RESETED:
		printf("%s\n","O timer não foi inicializado");		
		break;
	case STOPPED:
		printf("%s\n","O timer já está parado");		
		break;
	}	
}

int initTimer() 
{
	printf("%s\n","Iniciando o timer. tic tac" );
	timer_state = COUNTING;
	time(&timer_init);	
}

int stopTimer() 
{
	timer_state = STOPPED;
	printf("Timer parado. Levou %2.2f segundos para terminar\n", difftime(time(NULL),timer_init));
}

int timer_reset()
{
	printf("%s\n", "Timer resetado, use timer_begin_counting() para iniciá-lo");
	timer_state = RESETED;
	timer_init = NULL;	
}

