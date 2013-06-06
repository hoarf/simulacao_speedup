#include <mpi.h>
#include "timer.h"
#include "mds_calcula_media.h"

int main(int argc, char  *argv[])
{
	int  i;
	int total_processos, rank;

 	MPI_Init(&argc, &argv) ;
   	MPI_Comm_size(MPI_COMM_WORLD, &total_processos);
   	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	//Exemplo de como usar o timer
	timer_reset();
	timer_begin_counting();

	int vetor[8] = {10 ,2 ,10 ,5 ,7 ,8 ,1 ,100};
	float valor_media = mds_calcula_media(vetor,8);

	printf("O valor da média é %f\n", valor_media);
	//Exemplo de como imprimir o resultado do timer		
	timer_stop_counting();

	MPI_Finalize();

	return 0;
}
