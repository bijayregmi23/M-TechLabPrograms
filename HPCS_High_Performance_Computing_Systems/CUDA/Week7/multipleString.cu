#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>
#include<string.h>

__global__ void multipleString(char* a,char* b,int n,int dup){
    int i = threadIdx.x;
    for(int j=0;j<dup;j++){
        b[i+j*n] = a[i];
    }
}

int main(void){
    
    char *d_a, *d_b;
    int n, dup;
    char a[100], b[100];
    
    printf("\n\nEnter string : ");
    scanf("%s",a);
    n = strlen(a);
     
    printf("\nEnter number of Duplication : ");
    scanf("%d",&dup);
    
    cudaMalloc((void**)&d_a, ((sizeof(char))*n*dup));
    cudaMalloc((void**)&d_b, ((sizeof(char))*n*dup));
    
    cudaMemcpy(d_a,&a,((sizeof(char))*n), cudaMemcpyHostToDevice);
    multipleString<<<1,n>>>(d_a, d_b, n, dup);
    cudaMemcpy(&b,d_b,((sizeof(char))*n*dup),cudaMemcpyDeviceToHost);

    printf("\n\nResultant String : ");
    for (int i = 0; i <(n*dup); i++)
        printf("%c",b[i]);

    printf("\n\n");
    cudaFree(d_a);
    cudaFree(d_b);
    return 0;    
}