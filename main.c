#include "main.h"

//#define DATA_SIZE 200000000
#define DATA_SIZE 20

FILE * incializa_arquivo_ou_morre();
void finaliza_arquivo(FILE* arquivo);
void inicializa_buffer(int* buffer, int tamanho);

int main(int argc, char  *argv[])
{
    int proc_number, rank, sum, i;
    int * data;
    int * sub;
    float * averages;
    float * variances;
    float final_average;
    float final_variance;

    MPI_Init(&argc, &argv) ;
    printf("%d\n",MPI_Comm_size(MPI_COMM_WORLD, &proc_number));
    printf("Proc Number: %d\n",proc_number);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) 
    {
        averages = (float*)malloc(proc_number*sizeof(float));
        variances = (float*)malloc(proc_number*sizeof(float));
        data = (int*) malloc(DATA_SIZE*sizeof(int));
        for (i = 0; i < DATA_SIZE; ++i)
        {
            data[i] = 12 + i % 20;// / (DATA_SIZE/proc_number);
        }
    }

    sub = (int*) malloc(DATA_SIZE/proc_number*sizeof(int));

    MPI_Scatter(data, DATA_SIZE/proc_number, MPI_INT, sub, DATA_SIZE/proc_number,MPI_INT, 0, MPI_COMM_WORLD); 

    double variance_sum = 0;
    sum = 0;
    for( i = 0; i < DATA_SIZE/proc_number ; i++)
    { 
        sum = sum + sub[i];
        variance_sum += (sub[i])*(sub[i]);
    }
    float local_mean = ((float) (sum))/((float)(DATA_SIZE)/proc_number);
    float local_squared_mean = variance_sum/(DATA_SIZE/proc_number); 
    printf("Rank: %d\nSum: %d Local Mean: %f Local Variance: %f %f\n",rank,sum,local_mean,variance_sum,local_squared_mean);

    MPI_Gather(&local_mean,1,MPI_FLOAT,averages,1,MPI_FLOAT,0,MPI_COMM_WORLD);
    MPI_Gather(&local_squared_mean,1,MPI_FLOAT,variances,1,MPI_FLOAT,0,MPI_COMM_WORLD);
    if(rank == 0)
    {
        final_average = 0;
        final_variance = 0;
        for(i=0;i<proc_number;i++)
        {
               final_average += averages[i];
               final_variance += variances[i];
        }
        final_average = final_average/proc_number;
        final_variance = final_variance/proc_number - final_average*final_average;
        printf("Average: %f\n Variance: %f",final_average,final_variance);
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
