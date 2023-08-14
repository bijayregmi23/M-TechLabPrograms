#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void swapCase(char *a){
    int i = threadIdx.x;
    if (a[i] >= 'a' && a[i] <= 'z')
        a[i] = a[i] - 32;
    else if (a[i] >= 'A' && a[i] <= 'Z')
        a[i] = a[i] + 32;
}

int main(void)
{

    char *d_a;
    int n=0;

    char a[100];

    printf("\nEnter String : ");
    gets(a);

    while( a[n] != '\0')
        n++ ;
    n += 1;

    cudaMalloc((void **)&d_a, (sizeof(char) * n));

    
    cudaMemcpy(d_a, &a, (sizeof(char) * n), cudaMemcpyHostToDevice);
    
    swapCase<<<1,256>>>(d_a);

    cudaMemcpy(&a, d_a, (sizeof(char) * n), cudaMemcpyDeviceToHost);

    printf("\nResultant String : %s\n\n",a);

    cudaFree(d_a);
    // cudaFree(d_b);

    return 0;
}