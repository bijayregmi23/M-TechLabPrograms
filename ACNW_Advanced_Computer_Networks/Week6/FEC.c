#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, b, n1;
	int i, j;
	int a[20][20], r[20][20];

	printf("enter no of data chunks to be sent:\n");
	scanf("%d", &n);
	printf("enter no of bits to be sent in each data chunk:\n");
	scanf("%d", &b);
	printf("\nAT SENDER:\n");
	printf("enter data chunks to be sent (in binary) :\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < b; j++)
			scanf("%d", &a[i][j]);
	printf("adding redundant data chunk\n");
	printf("redundant bits added\n");
	printf("transmitting data chunks:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < b; j++)
			printf("%d ", a[i][j]);
		printf("\t");
	}
	printf("\n");
	printf("transmitting redundant bits:\n");
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < b; j++)
			if (a[i][j] == a[i + 1][j])
				a[i + 1][j] = 0;
			else
				a[i + 1][j] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < b; j++)
			if (i == n - 1)
				printf("%d ", a[i][j]);
	printf("\t");
	printf("\n\nAT RECEIVER:\n");
	printf("received data is:\n");
	printf("Enter the number of chunks of data received:\n");
	scanf("%d", &n1);
	if (n1 != n - 1)
	{
		printf("lost packets cannot be reconstructed\n");
		exit(0);
	}

	for (i = 0; i < n1; i++)
	{
		printf("enter bits of chunk %d:\n", i + 1);
		for (j = 0; j < b; j++)
			scanf("%d", &a[i][j]);
	}
	printf("enter bits of redundant chunk recieved:\n");
	for (j = 0; j < b; j++)
		printf("%d ", a[n - 1][j]);
	printf("\napplying error correction\n");
	printf("recieved data after error correction:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (i < n - 1)
				printf("%d ", a[i][j]);
		}
		printf("\t");
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < b; j++)
		{
			r[i][j] = a[i][j];
			a[i + 1][j] = a[i + 1][j] ^ a[i][j];
			if (i == n - 1)
				printf("%d ", r[i][j]);
		}
	}
	return 0;
}