#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *a, int key, int l, int r){
    if(r >= l){
        int mid = (l+r)/2;
        if(key == a[mid])
            return mid;
        else if( key < a[mid] )
            return binarySearch(a , key , l, mid-1);
        else
            return binarySearch(a , key , mid + 1, r);
    }
    return -1;
}

int main(){
    printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n\nBINARY SEARCH\n");

    int n,key,i;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);

    int *a = malloc(n*sizeof(int));
    printf("\nEnter the elements of Array : ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("\nArray elements are : ");
    for(i=0;i<n;i++) printf("%d    ",a[i]);

    printf("\n\nEnter search element : ");
    scanf("%d",&key);
    
    
    int result = binarySearch(a,key,0,n-1);

    (result==-1) ?  printf("\n%d not found in given array.\n", key)
                    :
                    printf("\n%d found at index %d\n", key,result);
                    

    printf("\n");
    return 0;
}