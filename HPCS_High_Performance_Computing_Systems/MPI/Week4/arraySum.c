#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int A[size][size], key, B[size], C[size][size], sum[size], i, j;
    if(rank == 0){
        printf("\nEnter the elements of Matrix(%d x %d) :\n",size,size);
        for(i=0 ;i<size ;i++)
            for(j=0 ;j<size ;j++)
                scanf("%d",&A[i][j]);
    }

    MPI_Scatter(&A, size, MPI_INT, &B, size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scan(&B, &sum, size, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    // printf("\n Processor %d |    sum : %d %d %d", rank, sum[0], sum[1], sum[2]);
    MPI_Gather(&sum, size, MPI_INT, &C, size, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank==0){
        printf("\nOUTPUT :\n");
        for(i=0 ;i<size ;i++){
            for(j=0 ;j<size ;j++)
                printf("%d\t",C[i][j]);
            printf("\n");
        }
    }


    MPI_Finalize();
    printf("\n");

    return 0;
}