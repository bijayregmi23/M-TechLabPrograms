#include <stdio.h>
int main()
{
    int num;
    /*This is a multiline Comment with single line*/
    printf("Enter an integer: ");
    scanf("%d", &num);

    // true if num is perfectly divisible by 2
    if (num % 2 == 0)
        printf("%d is even.", num);
    else
        printf("%d is odd.", num);

    print("Hi // This is a single line comment inside print(). Bye");

    /*
    This is a multiline comment with multiple lines
    if(num % 2 == 0)
        printf("%d is even.", num);
    else
        printf("%d is odd.", num);
    */

    print("Hi !/* This is a multiline comment inside print()*/ Bye");

    return 0;
}