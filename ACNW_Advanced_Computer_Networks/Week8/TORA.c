#include<stdio.h>

#define INFINITY 9999
#define MAX 10
 
void TORA(int G[MAX][MAX], int n, int startnode,int seq[MAX][MAX],int dest);
 
void main(){
	int G[MAX][MAX],seq[MAX][MAX],i, j, n, u, dest;
	
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
           seq[i][i] = 2*i*100;
        }
	printf("\nEnter the adjacency matrix::\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++){
			printf("\n Enter edge between %d to %d :",i,j);
			scanf("%d", &G[i][j]);
			if(G[i][j]!=0 && i!=j){
                           seq[i][j] = seq[i][i];
                       }
		}
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
        printf("Enter the detination \n");
        scanf("%d",&dest);
	TORA(G,n,u,seq,dest);
	
}
 
void TORA(int G[MAX][MAX], int n, int startnode,int seq[MAX][MAX],int dest)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j,k;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
					for(k=0;k<n;k++){
					   seq[i][k] = seq[i][k]+2;
					}
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i != startnode && i==dest)
		{   
		    printf("Route Discovery Packet \n");
			printf("\n Destination %d and %d as starting node = %d", i, startnode, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			k=0;
			do
			{
			    k++;
				j=pred[j];
				printf("<-Next node %d",j);
				printf(" Height: %d \n",k);
			}while(j!=startnode);
			printf("\n");
			
			printf("\n");
		}
        
}

