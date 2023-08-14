#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[] ){
    
    int rank,size;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
		printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n");

        int N,n,i,a[100],key,index = -1,index1;
        printf("\nEnter the size of Array : ");
        scanf("%d",&N);
        
        printf("\nEnter the elements of Array : ");
        for(i=0; i<N; i++) scanf("%d",&a[i]);

        printf("\nEnter the element to be searched : ");
            scanf("%d",&key);

        // Calculating n
        if(N%2 == 0)
            n=N/2;
        else
            n=(N/2)+1;
        
        MPI_Send(&N, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&a[n], (N-n), MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Send(&key, 1, MPI_INT, 1, 2, MPI_COMM_WORLD);

        for(i=0; i<n; i++){
            if(key == a[i]){
                index = i ;
                break;
            }
        }
            
        MPI_Recv(&index1, 1, MPI_INT, 1, 3, MPI_COMM_WORLD, &status);

        if(index == -1 && index1 == -1){
            printf("\n\n%d not found in given Array.", key);
        }
        else{
            if(index != -1)
                printf("\n\n%d found at index %d", key,index);
            if(index1 != -1)
                printf("\n\n%d found at index %d", key,index1+n);
        }             
    }

    else if(rank == 1){
        int a[100], N, n, i, key, index=-1;

        MPI_Recv(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        // Calculating n
        if(N%2 == 0) 
            n=N/2;
        else
            n=(N/2)+1 ;

        MPI_Recv(&a[0], N-n, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(&key, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);

        for(i=0; i<(N-n); i++){
            if(key == a[i]){
                index = i ;
                break;
            }
        }
        MPI_Send(&index, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);

    }
    MPI_Finalize();
    printf("\n");
    return 0;
}