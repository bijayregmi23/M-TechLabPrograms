#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[]){

	int rank,size;
	
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	int a,b,c,i,add,sub,div,mul;

	if(rank==0){
		printf("\nEnter the value of A : ");
		scanf("%d",&a);
		printf("\nEnter the value of B : ");
		scanf("%d",&b);

		// Sending the vlue of a and b to all processors
		for(i=1;i<size;i++){
			MPI_Send(&a, 1, MPI_INT,  i, i-1, MPI_COMM_WORLD);
			MPI_Send(&b, 1, MPI_INT,  i, (size + (i-2)), MPI_COMM_WORLD);
		}


		MPI_Recv(&add, 1, MPI_INT, 1, 8, MPI_COMM_WORLD, &status);
		printf("\nThe sum is : %d", add);

		MPI_Recv(&sub, 1, MPI_INT, 2, 9, MPI_COMM_WORLD, &status);
		printf("\nThe diffrence is : %d", sub);

		MPI_Recv(&mul, 1, MPI_INT, 3, 10, MPI_COMM_WORLD, &status);
		printf("\nThe product is : %d", mul);

		MPI_Recv(&div, 1, MPI_INT, 4, 11, MPI_COMM_WORLD, &status);
		printf("\nThe division is : %d\n\n", div);


	}


	else if(rank == 1){
		MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(&b, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
		c = a + b;
		MPI_Send(&c, 1, MPI_INT, 0, 8, MPI_COMM_WORLD);
	}
	else if(rank == 2){
		MPI_Recv(&a, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		MPI_Recv(&b, 1, MPI_INT, 0, 5, MPI_COMM_WORLD, &status);
		c = a - b;
		MPI_Send(&c, 1, MPI_INT, 0, 9, MPI_COMM_WORLD);
	}
	else if(rank == 3){
		MPI_Recv(&a, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&b, 1, MPI_INT, 0, 6, MPI_COMM_WORLD, &status);
		c = a * b;
		MPI_Send(&c, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
	}
	else if(rank == 4){
		MPI_Recv(&a, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
		MPI_Recv(&b, 1, MPI_INT, 0, 7, MPI_COMM_WORLD, &status);
		c = a / b;
		MPI_Send(&c, 1, MPI_INT, 0, 11, MPI_COMM_WORLD);
	}



	MPI_Finalize();
	return 0;
}