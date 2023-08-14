#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

	int i, j, N=0;
	char s1[100],s2[100];

    if(rank==0){
		printf("\nEnter the String S1 : ");
		gets(s1);
		printf("\nEnter the String S2 : ");
		gets(s2);
		// Finding Length of String
		while( s1[N] != '\0')
			N++ ;
        
    }
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if(N%size != 0){
        printf("\nLength Of string is not divisible by Total number of Processes ! \n");
        MPI_Finalize();
        return 0;
    }
    
    int len = N/size;

    char cs1[len], cs2[len], rs[2*len], S[(2*N)+1];

    MPI_Scatter(&s1[0], len, MPI_CHAR, &cs1, len, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(&s2[0], len, MPI_CHAR, &cs2, len, MPI_CHAR, 0, MPI_COMM_WORLD);

    j=0;
    for(i=0; i<len; i++){
        rs[j] = cs1[i];
        j+=1;
        rs[j] = cs2[i];
        j+=1;
    }

    MPI_Gather(&rs, 2*len, MPI_CHAR, &S, 2*len, MPI_CHAR, 0, MPI_COMM_WORLD);

    if(rank == 0){
        S[2*N] = '\0';
        printf("\nResultant String : %s\n\n",S );
    }

    MPI_Finalize();
    return 0;
}