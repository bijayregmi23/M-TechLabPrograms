#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

__global__ void sort(char *in, char *out, int n)
{
    int i = threadIdx.x; // current thread
    char iData = in[i];
    char iKey = iData;
    // Compute position of in[i] in output
    int pos = 0;
    for (int j = 0; j < n; j++)
    {
        char jKey = in[j]; // broadcasted
        int m = (jKey < iKey) || (jKey == iKey && j < i);
        pos += (m) ? 1 : 0;
    }
    out[pos] = iData;
}
int main()
{
    int n;
    char b[100];

    printf("\nEnter String : ");
    char string[8] = "HPCSLAB";
    n = strlen(string);
    printf("\nORIGINAL String : ");
    printf("%s", string);
    char *d_data_sorted, *d_data;
    int *count;
    cudaMalloc((void **)&d_data, sizeof(char) * n);
    cudaMalloc((void **)&d_data_sorted, sizeof(char) * n);
    cudaMalloc((void **)&count, sizeof(int));
    cudaMemcpy(d_data, &string, sizeof(char) * n, cudaMemcpyHostToDevice);
    cudaMemcpy(count, &n, sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, n> > >(d_data, d_data_sorted, n);
    cudaMemcpy(b, d_data_sorted, sizeof(char) * n, cudaMemcpyDeviceToHost);
    printf("\n\nSORTED String : ");
    printf("%s", b);
    printf("\n");
}
