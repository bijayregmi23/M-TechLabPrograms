#include<stdio.h>

# define INFINITY 999
# define MAX 10

typedef struct Node{
    int visited, distance;
    char predecessor;
}node;

void findPath(node vertex[MAX], int s, int d){
    int nextNode = d, count = 0;
    printf("\nSource : %c\tDestination : %c | \t\tPath : ",(char)(s+65),(char)(d+65));
    while(nextNode != s){
        printf("%c <----- ", (char)(nextNode + 65));
        nextNode = (int)vertex[nextNode].predecessor - 65;
        count ++;
    }
    printf("%c", (char)(nextNode + 65));
    printf("\nHop Count : %d\n\n",count);
}

void routingMethod(int cost[MAX][MAX], int s, int d, int n){
    int i;
    node vertex[MAX];
    for(i=0; i<n; i++){
        vertex[i].visited = 0;
        vertex[i].distance = cost[s][i];
        if(cost[s][i] == INFINITY)
            vertex[i].predecessor = '\0';
        else
            vertex[i].predecessor = (char)(s+65);
    }
    vertex[s].visited = 1;

    int nextNode = s, minDistance, iteration = 0;
    while(iteration < n-1){
        minDistance = INFINITY;
        for(i=0; i<n; i++){
            if(!vertex[i].visited && minDistance > vertex[i].distance){
                minDistance = vertex[i].distance;
                nextNode = i;
            }
        }

        vertex[nextNode].visited = 1;
        for(i=0; i<n; i++){
            if(!vertex[i].visited && vertex[i].distance > (minDistance + cost[nextNode][i]) ){
                vertex[i].distance = minDistance + cost[nextNode][i] ;
                vertex[i].predecessor = (char)(nextNode + 65);
            }
        }

        iteration++;
    }

    findPath(vertex, s, d);
}

int main(){
    int i, j;
    char source, destn;
    int s=0, d=4, n=6;

    int cost[MAX][MAX];
    printf("\nEnter the number of Vertices : ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix (INFINITY as 999) : \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            scanf("%d",&cost[i][j]);
    }

    // Printing Initial Cost Matrix
    printf("\nGiven Cost Matrix is : \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
                printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter Source : ");
    scanf("%s",&source);
    s = (int)source - 65;
    printf("\nEnter Destination : ");
    scanf("%s",&destn);
    d = (int)destn - 65;


    printf("\n\n------------\n  MIN-COST \n------------\n");
    routingMethod(cost, s, d, n);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
                if( i!=j && cost[i][j] != INFINITY)
                    cost[i][j] = 1;
        }
    }
    printf("\n\n------------\n  MIN-HOP \n------------\n");
    routingMethod(cost, s, d, n);

    return 0;

}