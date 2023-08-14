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
		int i, N=0, n;
		char A[100],B[100];
		printf("\nEnter the String : ");
		gets(A);
		// Finding Length of String
		while( A[N] != '\0')
			N++ ;
		// Finding n
        if(N%2==0)
		    n = N/2 ;
		else
		    n = (N/2)+1 ;	

		MPI_Ssend(&N,1,MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Ssend(&A[n],N-n,MPI_CHAR,1,1,MPI_COMM_WORLD);
		
		// Swapping Case from Processor 0
		for(i=0;i<n;i++){	
			if (A[i] >= 'a' && A[i] <= 'z')
				A[i] = A[i] - 32;
			else if (A[i] >= 'A' && A[i] <= 'Z')
				A[i] = A[i] + 32;
		}
		
		printf("\nSwapping case by PORCESSOR 0 : %s\n",A);

		// Recieving Second Half
		MPI_Recv(&B,N-n,MPI_CHAR,1,2,MPI_COMM_WORLD,&status);
		
		for(i=0;i<n;i++)
			A[n+i]=B[i];

		// Final String
		printf("\nResultant Word is: %s\n",A);
	}



	// PROCESSOR 1
	else if(rank==1)
	{
		int N,n,i;
		char B[100];
		MPI_Recv(&N,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		
		// Finding n
		if(N%2==0)
		    n=N/2;
		else
    		n=(N/2)+1;

		MPI_Recv(&B[0],N-n,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);

		// Swapping case by Processor 0
		for(i=0;i<(N-n);i++){	
			if (B[i] >= 'a' && B[i] <= 'z'){
				B[i] = B[i] - 32;
			}
			else if( B[i] >= 'A' && B[i] <= 'Z')
				B[i] = B[i] + 32;
		}
		B[i]='\0';
		printf("\nSwapping case by PORCESSOR 1 : %s\n",B);
    	// Sending Second Half
		MPI_Ssend(&B,(N-n),MPI_CHAR,0,2,MPI_COMM_WORLD);
	}
	MPI_Finalize();
    return 0;
}
