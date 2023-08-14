#include<stdio.h>
#include<mpi.h>

int checkPrime(int n){

	if(n==1)
		return 0;
	if(n==2)
		return 1;

	int i, flag=0;
	for(i=2; i<=n/2; i++){
		if(n%i == 0){
			flag=1;
			break;
		}
	}
	if(flag == 0)
		return 1;
	else
		return 0;
}


int main(int argc, char *argv[] ){
    
    int rank,size;

    MPI_Init(&argc,&argv);
    
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank==0){
		printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n\n");
    	
    	int N,n,i;

    	printf("\nEnter N : ");
		scanf("%d", &N);

        if(N%2==0)
		    n = N/2;
		else
		    n = (N/2)+1;

		MPI_Send(&N,1, MPI_INT, 1, 0, MPI_COMM_WORLD);

		printf("\nPrime Numbers found by PROCESSOR %d are : ",rank);
		for(i=1; i<=n; i++){
			if(checkPrime(i) == 1)
				printf("  %d",i);
    	}
    }
    else if(rank == 1){

    	int N,n,i;

    	MPI_Recv(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        if(N%2==0)
		    n = N/2;
		else
		    n = (N/2)+1;

		printf("\nPrime Numbers found by PROCESSOR %d are : ",rank);
		for(i = n+1; i<=N; i++){
			if(checkPrime(i) == 1)
				printf("  %d",i);
    	}
    }



    MPI_Finalize();
    printf("\n");
    return 0;
}