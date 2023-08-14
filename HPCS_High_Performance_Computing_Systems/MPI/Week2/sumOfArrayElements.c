#include<mpi.h>
#include <stdio.h>


int main(int argc,char* argv[])
{
	int rank,size;
    
    MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank==0)
	{

		printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n\n");
		int i, N=0, n, sum1=0, sum2;
		int A[100];
		
		printf("\nEnter the number of elements in the array : ");
		scanf("%d", &N);
		printf("\nEnter the array elements :");
		for(i=0;i<N;i++)
		    scanf("%d", &A[i]);
		
        if(N%2==0)
		    n = N/2;
		else
		    n = (N/2)+1;
		
		MPI_Send(&N,1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(&A[n], N-n, MPI_INT, 1, 1, MPI_COMM_WORLD);

		for(i=0;i<n;i++){
			sum1=sum1+A[i];
		}
		printf("\nSum by PROCESSOR 0 : %d\n",sum1);

		// Recieving Sum
		MPI_Recv(&sum2, N-n, MPI_INT, 1, 2, MPI_COMM_WORLD, &status);

		// Final Sum
		sum2=sum1+sum2;
		printf("\nSum of array elements is: %d\n",sum2);
	}
	else if(rank==1)
	{
		int i, N=0, n, sum2=0;
		int B[100];

		// Recieving 2nd Half
		MPI_Recv(&N,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		if(N%2==0)
		    n=N/2;
		else
    		n=(N/2)+1;
		
		MPI_Recv(&B[0],N-n,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		
		for(i=0;i<(N-n);i++){
			sum2=sum2+B[i];
		}
		printf("\nSum by PROCESSOR 1 : %d\n",sum2);
	
    	MPI_Send(&sum2,1,MPI_INT,0,2,MPI_COMM_WORLD);
	}
	MPI_Finalize();
    return 0;
}
