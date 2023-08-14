#include<stdio.h>
#include<mpi.h>

int factorial(int n){
    if( n==0 || n==1){
        return 1;
    }
    int result = 1;
    for(int i=2; i <=n ; i++){
        result = result * i;
    }
    return result;
}

int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int A[size], i, N;
    if(rank == 0){

        printf("\nEnter %d elements : ", size);
        for( i=0; i<size; i++)
            scanf("%d", &A[i]);
    }

    MPI_Scatter( &A[0] , 1, MPI_INT, &N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("\nPROCESSOR %d : Factorial of %d is %d", rank, N, factorial(N));

    MPI_Finalize();
    printf("\n");
    return 0;
}