#include<iostream>
using namespace std;
#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[]){
    int rank,size;
    
    // cout<<"\nargc : "<<argc<<"           argv : "<<argv[0]<<"            rank : "<<rank<<"              size : "<<size<<"\n";

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // cout<<"\nargc : "<<argc<<"           argv : "<<argv[0]<<"            rank : "<<rank<<"              size : "<<size<<"\n";

    if(rank == 0){
        char message[20] ;
        cout<<"\nEnter the message : ";
        cin>>message;
        int len = strlen(message);
        len = len + 1;
        MPI_Send(&len, 1, MPI_INT, 1, 0 ,MPI_COMM_WORLD);
        MPI_Send(&message,len,MPI_CHAR, 1, 1, MPI_COMM_WORLD);
    }
    else if(rank == 1){
        int len;
        char message1[20];
        MPI_Status status;
        int a = MPI_Recv(&len, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        int b = MPI_Recv(&message1, len, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);
        cout<<"\nProcess : 0 has sent the message : \n\n***"<<message1<<"***\n";
    }
    MPI_Finalize();
    return 0;
}