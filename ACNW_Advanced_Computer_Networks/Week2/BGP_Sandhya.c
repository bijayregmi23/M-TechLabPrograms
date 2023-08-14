#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int a[100][100],c[100][100];

void resetMatrix(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=0;
			c[i][j]=0;
		}
	}
}

void printAMatrix(int n){
	int i,j;
	printf("The adjacency matrix is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void createAMatrix(int n){
	int i,j,num;
	//Allow only 0 or 1 as input
	printf("Enter the adjacency matrix: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&num);
			if(num==0 || num==1){
				a[i][j]=num;
			}
			else{
				printf("Enter 0 or 1: \n");
				j=j-1;
			}
			if(i==j && a[i][j]!=0){
				a[i][j]=0;
			}
		}
	}
}

int validateAMatrix(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=a[j][i]){
				printf("The adjacency matrix is incorrect because A[i][j]!=A[j][i]");
				resetMatrix(n);
				return 1;
			}
		}
	}
	return 0;
}

void createCMatrix(int n){
	int i,j;
	//Create cost Matrix
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				c[i][j]=0;				
			}
			else if(a[i][j]==0){
				c[i][j]=99;
			}
			else if(a[i][j]==1 && c[i][j]==0){
				printf("Enter the cost from %c to %c: \n",i+65,j+65);
				scanf("%d",&c[i][j]);
				c[j][i]=c[i][j];
			}

		}
	}
}

void printCMatrix(int n){
	int i,j;
	printf("The cost matrix is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}

void dijkstra(int n,int startnode,int destnode)
{
 
	int distance[100],pred[100];
	int visited[100],count,mindistance,nextnode,i,j;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	// for(i=0;i<n;i++)
	// for(j=0;j<n;j++)
	// if(G[i][j]==0)
	// cost[i][j]=INFINITY;
	// else
	// cost[i][j]=G[i][j];
	// //initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=c[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=99;
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++){
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
		//check if a better path exists through nextnode
		visited[nextnode]=1;
		for(i=0;i<n;i++){
			if(!visited[i]){
				if(mindistance+c[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+c[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
	 
	//print the path and distance of each node
	for(i=startnode;i<=destnode;i++){
		if(i!=startnode)
		{
			printf("\nDistance of node %c=%d",i+65,distance[i]);
			printf("\nPath=%c",i+65);
			j=i;
		while(j!=startnode)
		{
			j=pred[j];
			printf("<-%c",j+65);
		}
		}
	}
}

int main(){

	int n,v=1,k=1,count=0;
	char src,dst;
	

	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	resetMatrix(n);
	createAMatrix(n);
	printAMatrix(n);//Prints Adjacency Matrix
	v=validateAMatrix(n);	//Check if the adjacency matrix entered by the user is correct
	while(k){
		if(v==0){
			createCMatrix(n);//Creates Cost Matrix
			printCMatrix(n);//Prints Cost Matrix
			k=0;
		}
		else{
			printf("Enter the number of nodes: \n");
			scanf("%d",&n);
			printf("Enter the correct Adjacency matrix: ");
			createAMatrix(n);
			v=validateAMatrix(n);
		}

	}
	printf("Enter the source node: \n");
	scanf(" %c",&src);
	printf("Enter the destination node: \n");
	scanf(" %c",&dst);

	// printf("Source = %c\ndestination=%c\n",src,dst);

	int s= ((int)toupper(src))-65;
	int d= ((int)toupper(dst))-65;
	// printf("%d %d\n",s,d);

	dijkstra(n,s,d);
	return 0;

}