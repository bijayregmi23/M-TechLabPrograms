#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void addArray(int *a, int *b, int *c){
    int j = threadIdx.x;
    c[j] = a[j] + b[j];
}

int main(void)
{
    int n;
    //Defining the size of an array
    printf("\nEnter size of array : ");
    scanf("%d", &n);

    // Initialising variables of the Host
    int a[n * 2], b[n * 2], c[n * 2], i;

    // Taking input of all A and B in Host Variables
    printf("\nEnter elements of A : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter elements of B : ");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    // Initialising variables for Device
    int *d_a, *d_b, *d_c;

    // Allocating Memory for all Device Variables
    cudaError_t cudaStatus = cudaMalloc((void **)&d_a, (sizeof(int) * n));
    if (cudaStatus != cudaSuccess){
        printf("CUDA Error1: %s\n", cudaGetErrorString(cudaStatus));
    }
    cudaMalloc((void **)&d_b, (sizeof(int) * n));
    cudaMalloc((void **)&d_c, (sizeof(int) * n));

    // Coping values of all the Host variables to Device variables
    cudaMemcpy(d_a, &a, (sizeof(int) * n), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, (sizeof(int) * n), cudaMemcpyHostToDevice);
    
    // Calling kernal to add Device variables A and B, and to store it in C
    addArray<<<1, n>>>(d_a, d_b, d_c);

    // Copying Device Variables to the Host variable
    cudaMemcpy(&c, d_c, (sizeof(int) * n), cudaMemcpyDeviceToHost);

    // Printing value stored in Host variable
    printf("\nResultant Array : ");
    for (i = 0; i < n; i++)
        printf("%d\t",c[i]);
    printf("\n\n");

    // Deallocating all the Host variables
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}