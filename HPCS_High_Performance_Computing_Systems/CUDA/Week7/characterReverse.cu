#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void characterReverse(char *a, char *b, int n){
    int i = threadIdx.x;
    if(i == n-1)
        b[i] = a[i];
    else
        b[i] = a[n-i-2];
}

int main(void)
{

    char *d_a, *d_b;
    int n=0;

    char a[100], b[100];

    printf("\nEnter String : ");
    gets(a);

    while( a[n] != '\0')
        n++ ;
    n += 1;

    cudaMalloc((void **)&d_a, (sizeof(char) * n));
    cudaMalloc((void **)&d_b, (sizeof(char) * n));
    
    cudaMemcpy(d_a, &a, (sizeof(char) * n), cudaMemcpyHostToDevice);
    characterReverse<<<1,256>>>(d_a, d_b, n);
    cudaMemcpy(&b, d_b, (sizeof(char) * n), cudaMemcpyDeviceToHost);


    printf("\nResultant String : %s\n\n",b);

    cudaFree(d_a);
    cudaFree(d_b);
    return 0;
}