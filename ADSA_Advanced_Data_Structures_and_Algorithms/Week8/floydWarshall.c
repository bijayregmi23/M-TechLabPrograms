#include<stdio.h>
#include<wchar.h>
#include<locale.h>

# define INFINITY 999
# define MAX 10

void printMatrix(int cost[MAX][MAX],char predicessor[MAX][MAX],int N){
    int i,j;
    printf("\nDISTANCE : \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(cost[i][j] == 999)
                printf("%lc\t",8734);
            else
                printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
    printf("\nPREDICESSOR : \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(predicessor[i][j] == '\0')
                printf("_\t");
            else
                printf("%c\t",predicessor[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    setlocale( LC_ALL, "en_US.UTF-8" );

    int N=4, i, j, iteration, start = 0 ;
    char s;
    // int cost[MAX][MAX];
    char predicessor[MAX][MAX] ;

    // int cost[MAX][MAX] = {
    //     {0, -1, 4, INFINITY, INFINITY},
    //     {INFINITY, 0, 3, 2, 2},
    //     {INFINITY, INFINITY, 0, INFINITY, INFINITY},
    //     {INFINITY, 1, 5, 0, INFINITY},
    //     {INFINITY, INFINITY, INFINITY, -3, 0}
    // };
    int cost[MAX][MAX] = {
        {0, INFINITY, INFINITY, INFINITY},
        {INFINITY, 0, 1, -3},
        {INFINITY, 3, 0, INFINITY},
        {2, INFINITY, 4, 0}
    };

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
            if(cost[i][j] > 900){
                printf("%lc\t",8734);
                predicessor[i][j] = '\0';
            }
            else{
                printf("%d\t",cost[i][j]);
                if(i==j)
                    predicessor[i][j]='\0';
                else
                    predicessor[i][j]=(char)(i+65);
            }
        }
        printf("\n");
    }
    iteration = 1;
    while(iteration < N){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(i!=j && iteration!=i && iteration!=j){
                    if(cost[i][iteration] != INFINITY && cost[iteration][j] != INFINITY && cost[i][j] > cost[i][iteration]+cost[iteration][j]){
                        cost[i][j]= cost[i][iteration]+cost[iteration][j];
                        predicessor[i][j] = (char)(iteration+65);
                    }
                }
            }
        }
        printf("\n\nIteration %d :",iteration);
        printMatrix(cost,predicessor,N);
        iteration++;
    }
    printf("\n\n\nFinal Cost Matrix is : ");
    printMatrix(cost,predicessor,N);

    printf("\n\n");
    return 0;
}