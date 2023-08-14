#include<stdio.h>
#include<wchar.h>
#include<locale.h>

# define INFINITY 999
# define MAX 10

typedef struct Vertex{
    int distance;
    char predecessor;
}Node;

int main(){

    setlocale( LC_ALL, "en_US.UTF-8" );

    int N=5, i, j, iteration, start = 0 ;
    char s;
    // int cost[MAX][MAX];
    int cost[MAX][MAX] = {
        {0, 4, 2, INFINITY, INFINITY},
        {INFINITY, 0, 3, 2, 3},
        {INFINITY, 1, 0, 4, 5},
        {INFINITY, INFINITY, INFINITY, 0, INFINITY},
        {INFINITY, INFINITY, INFINITY, -5, 0},
    };
    // int cost[MAX][MAX] = {
    //     {0, -1, 4, INFINITY, INFINITY},
    //     {INFINITY, 0, 3, 2, 2},
    //     {INFINITY, INFINITY, 0, INFINITY, INFINITY},
    //     {INFINITY, 1, 5, 0, INFINITY},
    //     {INFINITY, INFINITY, INFINITY, -3, 0}
    // };

    // printf("\nEnter the number of Vertices : ");
    // scanf("%d",&N);
    // printf("\nEnter the cost matrix (%lc as 999) : \n", 8734);
    // for(i=0; i<N; i++){
    //     for(j=0; j<N; j++)
    //         scanf("%d\t",&cost[i][j]);
    // }

    // Printing Initial Cost Matrix
    printf("\nGiven Cost Matrix is : \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(cost[i][j] == 999)
                printf("%lc\t",8734);
            else
                printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }

 
    
    Node node[MAX];

    // Declaring all vertex distance as INFINITY except Starting Vertex
    node[start].distance = 0;
    node[start].predecessor = (char)(start+65);
    for(i=0; i<N; i++){
        if(i != start){
            node[i].distance = INFINITY;
            node[i].predecessor = '\0';
        }
    }

    
    iteration=0;
    while(iteration<N-1){

        // Looping through all the edges
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(i!=j && cost[i][j] != INFINITY){
                    if(node[j].distance > node[i].distance + cost[i][j]){
                        node[j].distance = node[i].distance + cost[i][j];
                        node[j].predecessor = (char)(i+65);
                    }
                }
            }
        }
        // printf("\n\nIteration %d", iteration);
        // for(j=0;j<N;j++){
        //     printf("\nNode %c | Distance / Predecissor : %d/%c", j+65, node[j].distance, node[j].predecessor);
        // }
        iteration++;
    }

    // Printing Distance and Predicessor
    printf("\n\nDistance and Predicessor from  %c: \n",(char)(start+65));
    for(i=0;i<N;i++){
        printf("\nNode %c | Distance : %d\tPredecissor : %c", i+65, node[i].distance, node[i].predecessor);
    }

    // Finding Path for each vertex from start
    printf("\n\n\nPATH FROM %c\n",(char)(start+65));
    for(i=0; i<N; i++){
        if(i != start){

            printf("\nPath(%c) | ",(char)(i+65));
            j=i;
            while(j != start){
                printf("%c<-----",(char)(j+65));
                j=(int)(node[j].predecessor)-65;
            }
            printf("%c",(char)(start+65));
        }
    }


    printf("\n\n\n");
    return 0 ;
}