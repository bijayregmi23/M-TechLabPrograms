#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head;


void push(){
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nNot able to push element");
    }
    else{
        printf("\nEnter the value : ");
        scanf(" %d",&val);
        if(head==NULL){
            ptr->val = val;
            ptr -> next = NULL;
            head = ptr;
        }
        else{
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
    }
}

void pop(){
    int item;
    struct node *ptr;
    if (head == NULL){
        printf("\nSTACK IS EMPTY ! \n");
    }
    else{
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("\n%d poppd up \n",item);
    }
}

void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL){
        printf("\nSTACK IS EMPTY ! \n");
    }
    else{
        printf("\nStack elements are :    ");
        while(ptr!=NULL){
            printf("%d\t",ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main ()
{
    printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n");
    printf("\nSTACK OPERATION\n");

    int choice=0;
    while(choice != 4){
        printf("\n\n1. Push\n2. Pop\n3. Display\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                printf("\nINVALID INPUT!\n");
            }
        };
    }
    return 0;
}

