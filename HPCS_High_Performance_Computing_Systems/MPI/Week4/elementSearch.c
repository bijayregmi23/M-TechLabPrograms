#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int A[size][size], key, B[size], count = 0 , totalCount, i, j;
    if(rank == 0){
        printf("Enter the elements of Matrix(%d x %d) :\n",size,size);
        for(i=0 ;i<size ;i++)
            for(j=0 ;j<size ;j++)
                scanf("%d",&A[i][j]);

        printf("\nEnter the element to be searched in Matrix\n");
        for(i=0 ;i<size ;i++){
            for(j=0 ;j<size ;j++){
                printf("%d\t",A[i][j]);
            }
            printf("\n");
        }
        scanf("\n%d",&key);
    }
    MPI_Bcast(&key, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(&A, size, MPI_INT, &B, size, MPI_INT, 0, MPI_COMM_WORLD);

    for(i=0 ;i<size ;i++){
        if(B[i] == key)
            count++;
    }

    MPI_Reduce(&count, &totalCount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0)
        printf("\nTotal number of %d in Matrix are : %d",key,totalCount);

    MPI_Finalize();
    printf("\n");
    return 0;
}