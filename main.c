#include "timer.h"

int main(int argc, char const *argv[])
{
	int  i;
	int total_processos, rank;

 	MPI_Init(&argc, &argv) ;
   	MPI_Comm_Size(MPI_COMM_WORLD, &total_processos);
   	MPI_Comm_Rank(MPI_COMM_WORLD, &rank);
	
	//Exemplo de como usar o timer
	timer_reset();
	timer_begin_counting();
		
	//Exemplo de como imprimir o resultado do timer		
	timer_stop_counting();

	MPI_Finalize();

	return 0;
}
