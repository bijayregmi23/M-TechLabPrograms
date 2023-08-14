#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void swapAlternate(int *a, int *b, int n){
    int i = threadIdx.x;
    if (i % 2 == 0){
        b[i] = a[i + 1];
        b[i + 1] = a[i];
    }
    if(n%2 == 1)
        b[n-1] = a[n-1];
}

int main(void){
    int *d_a, *d_b, n;
    
    printf("\nEnter size of array : ");
    scanf("%d", &n);

    int a[n], b[n], i;
    cudaMalloc((void **)&d_a, (sizeof(int) * n));
    cudaMalloc((void **)&d_b, (sizeof(int) * n));

    
    printf("\nEnter the elements of array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\n");
    
    cudaMemcpy(d_a, &a, (sizeof(int) * n), cudaMemcpyHostToDevice);
    
    swapAlternate<<<1,256>>>(d_a, d_b, n);

    cudaMemcpy(&b, d_b, (sizeof(int) * n), cudaMemcpyDeviceToHost);
    printf("\nResultant array : ");
    for (int i = 0; i < n; i++)
        printf("%d  ", b[i]);
    printf("\n");

    cudaFree(d_a);
    cudaFree(d_b);
    return 0;
}