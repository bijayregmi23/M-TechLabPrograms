#include<stdio.h>

int power(int base,int exp){
    int i;
    int res = 1;
    for(i = 0; i < exp; i++ )
        res = res * base;
    return res;
}

void main(){
    printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n");
    printf("\nK-BIT BINARY COUNTER\n");

    int i, j, k, n, cost=0, count=0;
    printf("\nEnter the value of k : ");
    scanf("%d",&k);
    
    char str[k];
    for(i = 0; i < k; i++ )
        str[i] = '0';

    printf("\n");

    n = power(2,k);
    for(j=0 ; j<n ; j++ ){
        // 1bit Incrementer
        i = k - 1;
        printf("\nDecimal Value : %d\t Binary Value : %s\tCount : %d\tAmortized Cost : %d", j, str, count, cost);
        while (str[i] == '1') {
            str[i] = '0';
            cost++;
            i--;
        }
        if (i >= 0){
            str[i] = '1';
            cost++;
        }
        count++;
        // printf("\nDecimal Value : %d\t Binary Value : %s\tCount : %d\tCost : %d", j, str, count, cost);
    }
    j=0;
    printf("\nDecimal Value : %d\t Binary Value : %s\tCount : %d\tAmortized Cost : %d", j, str, count, cost);

    printf("\n");
}