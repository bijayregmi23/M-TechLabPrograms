#include<stdio.h>

# define INFINITY 999

int n=5;
int A[5][5] = {
    {0,2,999,999,5},
    {2,0,4,999,3},
    {999,4,0,4,2},
    {999,999,4,0,1},
    {5,3,2,1,0}
};
int C[5][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

void createCostMatrix(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                if(A[i][j] != INFINITY)
                    C[i][j] = 1;    
            }
        }
    }
}

void dijkstra(int source, int dest){
    int visited[5];
    int predecissor[5];
    int distance[5] = { INFINITY, INFINITY, INFINITY, INFINITY, INFINITY};


    int minnode = 0,count=1 ;
    predecissor[source] = 0;
    distance[source] = 0;
    visited[source] = 1;
    int nextnode = source;
    while(count!= n)
    {

        for(i=0;i<n;i++){
            if(a[nextnode][i]<INFINITY)
        }
    }
}


int main(){

    int s,d;
    createCostMatrix();
    printf("\nEnter Source Node : ");
    scanf("%d", s);
    printf("\nEnter Destination Node : ");
    scanf("%d\n\n", d);

    dijkstra(s,d);

    return 0;
}