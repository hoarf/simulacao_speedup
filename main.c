#include "main.h"

#define TAMANHO_PROBLEMA 100

FILE * incializa_arquivo_ou_morre();
void finaliza_arquivo(FILE* arquivo);
void inicializa_buffer(int* buffer, int tamanho);

int main(int argc, char  *argv[])
{
    int total_processos, rank, sum, i;
    float media;
    int * main;
    int * sub;
    int * result;

    MPI_Init(&argc, &argv) ;
    printf("%d",MPI_Comm_size(MPI_COMM_WORLD, &total_processos));
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) 
    {
    	result = (int*)malloc(total_processos*sizeof(int));
    	main = (int*) malloc(TAMANHO_PROBLEMA*sizeof(int));
    	for (i = 0; i < TAMANHO_PROBLEMA; ++i)
	    	main[i] = i;
    }

	sub = (int*) malloc(TAMANHO_PROBLEMA/total_processos*sizeof(int));
    
    MPI_Scatter(main, TAMANHO_PROBLEMA/total_processos, MPI_INT, sub, TAMANHO_PROBLEMA/total_processos,MPI_INT, 0, MPI_COMM_WORLD); 
	
    sum = 0;
    for( i = 0; i < TAMANHO_PROBLEMA/total_processos ; i++)
            sum=sum+sub[i];

    printf("Rank= %d Soma= %d\n ",rank,sum);

      MPI_Gather(&sum,1,MPI_INT,result,1,MPI_INT,0,MPI_COMM_WORLD);
	
	 if(rank == root){
	 	  // TODO  Rotina que calcula a media
	 }


    MPI_Finalize();
	exit(0);
}

FILE * incializa_arquivo_ou_morre()
{
	FILE* arquivo = fopen("array.txt", "r");
	if (arquivo == NULL)
	{
		printf("Não foi possível abrir o arquivo\n");
		exit(1);
	}
	printf("Arquivo aberto com sucesso...\n");
	return arquivo;
}

void finaliza_arquivo(FILE * arquivo)
{
	printf("Fechando arquivo...\n");
	fclose(arquivo);
}
