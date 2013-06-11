#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE  259459200 

int main(int argc, char  *argv[])
{
    int proc_number, rank, sum, i;
    int * data;
    int * sub;
    float * averages;
    float * variances;
    float local_mean;
    float local_squared_mean;
    float final_average[1];
    float final_variance[1];

    MPI_Init(&argc, &argv) ;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_number);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) 
    {
        averages = (float*)malloc(proc_number*sizeof(float));
        variances = (float*)malloc(proc_number*sizeof(float));
        data = (int*) malloc(DATA_SIZE*sizeof(int));
        for (i = 0; i < DATA_SIZE; ++i)
        {
            data[i] = 12 + (i % 20);
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
    
    local_mean = ((float) (sum))/((float)(DATA_SIZE)/proc_number);
    local_squared_mean = variance_sum/(DATA_SIZE); 
    
    MPI_Reduce(&local_mean,final_average,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&local_squared_mean,final_variance,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    
    if(rank == 0)
    {
        final_average[0] = final_average[0]/proc_number;
        final_variance[0] = final_variance[0] - final_average[0]*final_average[0];
        printf("Average: %f\nVariance: %f\n",final_average[0],final_variance[0]);
    }


    MPI_Finalize();
    exit(0);
}
