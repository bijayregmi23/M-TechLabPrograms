#include<stdio.h>
#include<stdlib.h>
#define inf 999
#define max 10

void djikstras(int graph[max][max],int start,int n){
    int cost[max][max],visited[max],distance[max],predicissor[max];
    int count,i,j,min_dist,next_node;

    //Entering the cost matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(graph[i][j]==0)
                cost[i][j]=inf;
            else
                cost[i][j]=graph[i][j];
        }
    }

    for (i=0;i<n;i++){
        visited[i]=0;
        distance[i]=cost[start][i];
        predicissor[i]=start;
    }
    count=1;
    visited[start]=1;
    distance[start]=0;

    while(count< (n-1))
    {
        min_dist=inf;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && distance[i]<min_dist){
            min_dist=distance[i];
            next_node=i;
            }
        }
        visited[next_node]=1;
        for(i=0;i<n;i++){
            if(!visited[i])
            {
                if(min_dist+cost[next_node][i]<distance[i]){
                distance[i]=min_dist+cost[next_node][i];
                predicissor[i]=next_node;
                }
            }
            count++;
        }
        for(i=0;i<n;i++){
            if(i!=start)
            {
                printf("\nDistance to node %d is %d",i,distance[i]);
                printf("\nPath :             %d",i);
                j=i;
                do{
                    j=predicissor[j];
                    printf("<-%d",j);
                }while(j!=start);
            }
        }
    }
}

int main(){
    int n, graph[max][max],i,j,s,choice;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);

    printf("Enter the cost matrix: ");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    printf("The initial cost matrix is: \n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t\t",graph[i][j]);
        }
        printf("\n");
    }
    printf("Enter the starting node: \n");
    scanf("%d",&s);
    djikstras(graph,s,n);
    printf("\n");

    return 0;
}