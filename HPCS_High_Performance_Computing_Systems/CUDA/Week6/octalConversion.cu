#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void octalConversion(int *a, int *b){
    int i = threadIdx.x;

    // Converts decimal to octal
    int n = a[i], res = 0, multiplier = 1;
    while(n!=0){
        res = res + (multiplier * (n%8));
        n = n/8;
        multiplier = multiplier * 10;
    }

    b[i] = res;
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
    
    octalConversion<<<1,256>>>(d_a, d_b);

    cudaMemcpy(&b, d_b, (sizeof(int) * n), cudaMemcpyDeviceToHost);
    printf("\nResultant octal values : ");
    for (int i = 0; i < n; i++)
        printf("%d  ", b[i]);
    printf("\n");

    cudaFree(d_a);
    cudaFree(d_b);
    return 0;
}