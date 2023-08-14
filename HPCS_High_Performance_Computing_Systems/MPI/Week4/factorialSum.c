#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double t1,t2,absTime,totalTime;
    t1 = MPI_Wtime();

    float sum, fact, N;
    N = rank+1;
    MPI_Scan(&N, &fact, 1, MPI_FLOAT, MPI_PROD, MPI_COMM_WORLD);
    MPI_Scan(&fact, &sum, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);

    printf("\nPROCESSOR %d | Factorial sum : %d\n", rank, (int)sum);

    t2 = MPI_Wtime();
    absTime =t2-t1;
    MPI_Scan(&absTime, &totalTime, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    if(rank == size -1)
        printf("\nTotal time taken is %lf\n", totalTime);

    MPI_Finalize();
    printf("\n");
    return 0;
}