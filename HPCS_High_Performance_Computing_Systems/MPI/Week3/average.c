#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    int A[100], i, M ;
    
    if(rank == 0){
        printf("\nEnter M : ");
        scanf("%d",&M);
        printf("\nEnter %d Elements : ",(size * M));
        for(i=0; i<(size * M); i++)
            scanf("%d",&A[i]);
    }



    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    int B[M];
    MPI_Scatter(&A[0], M, MPI_INT, &B, M, MPI_INT, 0, MPI_COMM_WORLD);
    
    // Calculating avg of each fragments
    float avg=0;
    for(i=0; i<M; i++)
        avg = avg + B[i];
    avg = avg / M;

    float AVG[size];
    // Recieving all avg in array AVG[size]
    MPI_Gather(&avg, 1, MPI_FLOAT, &AVG, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
    
    if(rank == 0){

        float res = 0;
        for(i=0; i<size; i++){
            res = res + AVG[i];
            // printf("Partial Average%f\n", AVG[i]);
        }
        res = res/size;
        printf("\nAverage of %d elements are %f\n", (size * M), res);
    }

    MPI_Finalize();
    return 0;

}