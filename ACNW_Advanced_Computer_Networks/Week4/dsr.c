#include<stdio.h>

#define MAX 10
#define INFINITY 999

struct RREQ{
    int flag, id, source, destn, hopCount, path[20];
};

int main(){
    int source, destination, currentNode, i, j;

    int C[MAX][MAX] = {
        {0,  1,   0,   0,   0,   1},
        {1,  0,   1,   0,   1,   1},
        {0,  1,   0,   1,   1,   1},
        {0,  0,   1,   0,   1,   0},
        {0,  1,   1,   1,   0,   1},
        {1,  1,   1,   0,   1,   0}
    };
    int n=6;
    struct RREQ packet[n];
    for(i=0; i<n; i++)
        packet[i].flag = 0;


    printf("\nEnter Source Node : ");
    scanf("%d",&source);
    printf("\nEnter Destination Node : ");
    scanf("%d",&destination);

    packet[source].flag = 1;    
    packet[source].id = 100;
    packet[source].source = source;
    packet[source].destn = destination;
    packet[source].hopCount = 0;
    packet[source].path[packet[source].hopCount] = source;

    currentNode = source;

    while(packet[currentNode].flag == 1 && currentNode != destination){

        for(i=0; i<n; i++){
            if(currentNode != i && C[currentNode][i] != 0 && packet[i].flag != 1){
                packet[i].flag = 1;
                packet[i].id = packet[currentNode].id;
                packet[i].source = packet[currentNode].source;
                packet[i].destn = packet[currentNode].destn;
                packet[i].hopCount =  packet[currentNode].hopCount + 1;
                for(j=0; j<=packet[currentNode].hopCount; j++)
                    packet[i].path[j] = packet[currentNode].path[j];
                packet[i].path[j] = i;
            }
        }
        currentNode += 1;
        if(currentNode == n)
            currentNode = 0;
    }

    printf("\nRREQ Packet\n\nId : %d\nSource : %d\nDestination : %d\nHop Count : %d\nPath : ",
     packet[currentNode].id, packet[currentNode].source, packet[currentNode].destn, packet[currentNode].hopCount);
    for(j=0; j<packet[currentNode].hopCount; j++)
        printf("%d\t",packet[currentNode].path[j]);
    printf("\n");    

}