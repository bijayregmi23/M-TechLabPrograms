#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int *a , int n){
    int i,j,min;

    for(i=0; i<n; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[min]>a[j])
                min=j;
        }
        swap(&a[i],&a[min]);
    }
}

int main(){
    printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n\nSELECTION SORT\n");

    int n,i;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);

    int *a = malloc(n*sizeof(int));
    printf("\nEnter the elements of Array : ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("\nArray (UNSORTED) : ");
    for(i=0;i<n;i++) printf("%d    ",a[i]);

    selectionSort(a , n);

    printf("\nArray (SORTED) : ");
    for(i=0;i<n;i++) printf("%d    ",a[i]);                    

    printf("\n");
    return 0;
}