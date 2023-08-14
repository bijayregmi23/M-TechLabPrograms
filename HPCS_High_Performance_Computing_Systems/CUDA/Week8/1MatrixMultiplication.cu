#include <stdio.h>
#include <cuda.h>
#define BLOCK_SIZE 16

__global__ void gpu_matrix_mult(int *a, int *b, int *c, int m, int n, int k)
{
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int sum = 0;
    if (col < k && row < m)
    {
        for (int i = 0; i < n; i++)
        {
            sum += a[row * n + i] * b[i * k + col];
        }
        c[row * k + col] = sum;
    }
}

int main(int argc, char const *argv[])
{
    int m, n, k;

    printf("\nEnter M : ");
    scanf("%d", &m);
    printf("\nEnter N : ");
    scanf("%d", &n);
    printf("\nEnter K : ");
    scanf("%d", &k);

    // allocate memory in host RAM
    int *h_a, *h_b, *h_c;
    cudaMallocHost((void **)&h_a, sizeof(int) * m * n);
    cudaMallocHost((void **)&h_b, sizeof(int) * n * k);
    cudaMallocHost((void **)&h_c, sizeof(int) * m * k);

    // random initialize matrix A
    printf("\n\nEnter Matrix A : \n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &h_a[i * n + j]);
        }
    }

    // random initialize matrix B
    printf("\nEnter Matrix B : \n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            scanf("%d", &h_b[i * k + j]);
        }
    }

    float gpu_elapsed_time_ms;

    // some events to count the execution time
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // start to count execution time of GPU version
    cudaEventRecord(start, 0);
    // Allocate memory space on the device
    int *d_a, *d_b, *d_c;
    cudaMalloc((void **)&d_a, sizeof(int) * m * n);
    cudaMalloc((void **)&d_b, sizeof(int) * n * k);
    cudaMalloc((void **)&d_c, sizeof(int) * m * k);

    // copy matrix A and B from host to device memory
    cudaMemcpy(d_a, h_a, sizeof(int) * m * n, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, sizeof(int) * n * k, cudaMemcpyHostToDevice);

    unsigned int grid_rows = (m + BLOCK_SIZE - 1) / BLOCK_SIZE;
    unsigned int grid_cols = (k + BLOCK_SIZE - 1) / BLOCK_SIZE;
    dim3 dimGrid(grid_cols, grid_rows);
    dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);

    gpu_matrix_mult<<<dimGrid, dimBlock> > >(d_a, d_b, d_c, m, n, k);

    // Transfer results from device to host
    cudaMemcpy(h_c, d_c, sizeof(int) * m * k, cudaMemcpyDeviceToHost);
    cudaThreadSynchronize();
    // time counting terminate
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    // compute time elapse on GPU computing
    cudaEventElapsedTime(&gpu_elapsed_time_ms, start, stop);
    printf("\nTime elapsed on matrix multiplication of %dx%d . %dx%d on GPU: %f ms.\n\n", m, n, n, k, gpu_elapsed_time_ms);

    // validate results computed by GPU
    printf("\n\nResultant Matrix C : \n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            printf("%d ", h_c[i * k + j]);
        }
        printf("\n");
    }

    // free memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    cudaFreeHost(h_a);
    cudaFreeHost(h_b);
    cudaFreeHost(h_c);
    return 0;
}
