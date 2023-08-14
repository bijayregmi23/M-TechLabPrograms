#include<iostream>
using namespace std;
// #include<stdio.h>
void printMessage(char* m){
    cout<<m;
}

int main(int argc, char *argv[]){

    // INTEGER

    // int num = 10;
    // int *pnum ;
    // pnum = &num;
    // cout<<"\nnum : "<<*pnum<<"\n";
    // cout<<"Address of num : "<<pnum<<"\n";
    

    // CHARACTER

    // char c = 'B';
    // char *pc;
    // pc = &c;
    // cout<<"\nc : "<<*pc<<"\n";
    // cout<<"Address of num : "<<&c<<"\n";


    //CHARACTER ARRAY

    char message[] = "Hello";
    char *m = message;
    cout<<"\nMessage : "<<*m<<"\n";
    cout<<"Address of Message : "<<*m<<"\n";


    // FUNCTION
    // printMessage(&message[0]);

    return 0;
}