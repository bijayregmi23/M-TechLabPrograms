#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *a , int n){
    int i,j;

    for(i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if(a[j]>a[j+1])
                swap( &a[j], &a[j+1]);

}

int main(){
    printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n\nBUBBLE SORT\n");

    int n,i;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);

    int *a = malloc(n*sizeof(int));
    printf("\nEnter the elements of Array : ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("\nArray (UNSORTED) : ");
    for(i=0;i<n;i++) printf("%d    ",a[i]);

    bubbleSort(a , n);

    printf("\nArray (SORTED) : ");
    for(i=0;i<n;i++) printf("%d    ",a[i]);                    

    printf("\n");
    return 0;
}