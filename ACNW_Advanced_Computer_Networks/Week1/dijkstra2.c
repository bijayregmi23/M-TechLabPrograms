#include<stdio.h>
#include<stdlib.h>

#define inf 999
#define MAX 10


void calculate(int graph[MAX][MAX],int n){
	int count, i,j;
	int isolated[n];
	int max = -1;
	int min = 999;
	int isisolated = 0;

	for(i-0;i<n;i++)
		isolated[i]=0;
	for(i=0;i<n;i++){
		count = 1;
		for(j=0;j<n;j++){
			if(graph[i][j]>max && (graph[i][j] != inf))
				max=graph[i][j];
			if(graph[i][j]<min && (graph[i][j] != 0))
				min = graph[i][j];
			if(graph[i][j] == inf)
				count++;
		}
	
		if(count == n){
			isolated[i] = 1;
			isisolated = 1;
		}
	}
	printf("\nLargest cost in the graph is : %d", max);
	printf("\nSmallest cost in the graph is : %d", min);
	printf("\nIsolated nodes in the graph is are : ");
	if(isisolated == 1){
		for(i=0; i<n; i++){
			if(isolated[i] == 1)
				printf("%d\t",i);
		}
	}
	else
		printf("None");
}


int main(){
	int n, graph[MAX][MAX], i, j, s, choice;

	printf("Enter the number of vertices : \n");
	scanf("%d",&n);

	printf("\nEnter the cost matrix : \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);

	printf("\nInitial cost matrix is : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t\t",graph[i][j]);
		}
		printf("\n");
	}

	calculate(graph,n);


	return 0;
}
