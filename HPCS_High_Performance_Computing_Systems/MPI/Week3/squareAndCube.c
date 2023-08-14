#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    int A[100], i, j, M ;
    
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
    
    // Calculating power of each fragments
    for(i=0; i<M; i++){
        B[i] = (int)pow((float)B[i],rank+2);
        // printf("\n%d",B[i]);
    }
    int ANS[size * M];
    // Recieving all avg in array AVG[size]
    MPI_Gather(&B[0], M, MPI_INT, &ANS, M, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0){
        printf("\n");
        for(i=0; i<size; i++){
            for(j=0; j<M; j++)
                printf("\nThe %d power of %d is %d", i+2 ,A[(M*i)+j], ANS[(M*i)+j]);
        }
        printf("\n\n");
    }

    MPI_Finalize();
    return 0;

}