#include<stdio.h>

#define MAX 10
#define INFINITY 999

typedef struct node{
    int visited, distance;
    char predecessor;
}node;

void display(node vertex[MAX], int n){
    int i;
    for(i=0; i<n; i++)
        printf("\nNODE %c |\t\tDistance : %d\tPredicessor : %c", (char)(i+65), vertex[i].distance, vertex[i].predecessor);
}


//Dijkstra Function
void dijkstra(int G[MAX][MAX], int start, int n){
    int i;
    node vertex[MAX];
    
    // Initialising starting condition
    for(i=0; i<n; i++){
        vertex[i].distance = G[start][i];
        if(G[start][i] == INFINITY)
            vertex[i].predecessor = '\0';
        else
            vertex[i].predecessor = (char)(start+65);
        vertex[i].visited = 0;
    }
    vertex[start].visited = (char)(start+65);

    int iteration = 1;
    int minDistance, nextNode;
    while (iteration != n){
        // finding minIndex
        minDistance = INFINITY;
        for(i=0 ; i<n ; i++)
            if(
                vertex[i].visited == 0 && 
                vertex[i].distance < minDistance
            ){
                minDistance = vertex[i].distance;
                nextNode = i;
            }

        // comparing paths
        for(i=0 ; i<n ; i++)
            if(vertex[i].visited == 0){

                if(
                    i != nextNode &&
                    vertex[i].distance > (vertex[nextNode].distance + G[nextNode][i])
                ){
                    vertex[i].distance = vertex[nextNode].distance + G[nextNode][i];
                    vertex[i].predecessor = (char)(nextNode +65);
                }
            }
        vertex[nextNode].visited = 1;

        iteration++;
    }
    display(vertex,n);
}


int main(){
    int n = 5;

    int G[MAX][MAX] = {
        {0, 4, 2, INFINITY, INFINITY},
        {INFINITY, 0, 3, 2, 3},
        {INFINITY, 1, 0, 4, 5},
        {INFINITY, INFINITY, INFINITY, 0, INFINITY},
        {INFINITY, INFINITY, INFINITY, 1, 0}
    };

    int start = 0 ;

    dijkstra(G, start, n);

    return 0;
}