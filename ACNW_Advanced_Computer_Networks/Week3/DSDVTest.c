#include<stdio.h>

#define INFINITY 999
#define MAX 10

int main(){
    enum columnValues {destination , cost, nextLink, sequenceNumber};
    int n, i, j, currentNode;
    n = 6;
    int C[MAX][MAX] = {
        {0,  1,   999,   999,   999,   1},
        {1,  0,   2,   999,   4,   3},
        {999,  2,   0,   1,   2,   3},
        {999,  999,   1,   0,   2,   999},
        {999,  4,   2,   2,   0,   3},
        {1,  3,   3,   999,   3,   0}
    };
    int RT[MAX][4*MAX];

    // Initialising Routing Tables.
    for(currentNode=0; currentNode<n; currentNode++){
        for(i=0;i<n;i++){
            RT[i][(4*currentNode)+destination] = i;
            if(C[currentNode][i] == 999){
                RT[i][(4*currentNode)+cost] = C[currentNode][i];
                RT[i][(4*currentNode)+nextLink] = -1;

            }
            else{
                RT[i][(4*currentNode)+cost] = C[currentNode][i];
                RT[i][(4*currentNode)+nextLink] = i;
            }
            RT[i][(4*currentNode)+sequenceNumber] = 1000;
        }
    }

    for(currentNode=0; currentNode<n; currentNode++){
        printf("\n-------------------------");
        printf("\nROUTING TABLE FOR NODE %d",currentNode);
        printf("\n-------------------------");
        printf("\n\nD\tC\tN\tS\n");
        for(i=0;i<n;i++){
            printf("%d\t%d\t%d\t%d\n", 
            RT[i][(4*currentNode)+destination], 
            RT[i][(4*currentNode)+cost], 
            RT[i][(4*currentNode)+nextLink], 
            RT[i][(4*currentNode)+sequenceNumber]
            );
        }
        printf("\n\n");
    }


    int infinityFlag=0;
    // while(infinityFlag != 1){
        
    //     currentNode=0;
    //     while(currentNode<n){
    //         for(i=0;i<n;i++){
    //             if( RT[i][(4*currentNode)+cost] != 0 && RT[i][(4*currentNode)+cost] != 999 ){

    //                for(j=0;j<n;j<n){
                         
    //                }




    //             }
    //         }
    //         currentNode++;
    //     }
    // }

}