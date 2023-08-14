#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
};
struct node *front,*rear,*temp,*f1;
int Qsize = 0;

void create(){
    front = rear = NULL;
}

void queuesize(){
    printf("\nQueue size : %d", Qsize);
}

void enqueue(int data){
    if (rear == NULL){
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else{
        temp=(struct node *)malloc(1*sizeof(struct node));
        temp->info = data;
        temp->ptr = NULL;
        rear->ptr = temp;
        rear = temp;
    }
    Qsize++;
}

void display()
{
    f1 = front;
    if ((f1 == NULL) && (rear == NULL)){
        printf("\nQUEUE is empty\n");
        return;
    }
    while (f1 != rear){
        printf("%d ", f1->info);
        f1 = f1->ptr;
    }
    if (f1 == rear)
        printf("%d", f1->info);
}

void dequeue()
{
    f1 = front;
    if (f1 == NULL){
        printf("\nError: Trying to delete elements from empty queue.");
        return;
    }
    else{
        if (f1->ptr != NULL)
        {
            f1 = f1->ptr;
            printf("\nDequed value : %d", front->info);
            free(front);
            front = f1;
        }
        else
        {
            printf("\nDequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        Qsize--;
    }
}

int front_element(){
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}

void empty()
{
if ((front == NULL) && (rear == NULL))
    printf("\nQueue is empty\n");
else
    printf("\nQueue is not empty\n");
}

int main()
{
    printf("\nStudent name : BIJAY REGMI\nRegistration Number : 210913032");
    printf("\n\nQUEUE OPERATIONS\n");

    int n, choice, e;
    create();
    while (1){
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Front element");
        printf("\n4. Empty");
        printf("\n5. Display");
        printf("\n6. Queue size");
        printf("\n7. Exit");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter an element to insert : ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                e = front_element();
                if (e != 0)
                    printf("Front element is : %d", e);
                else
                    printf("\nQueue is empty\n");
                break;
            case 4:
                empty();
                break;
            case 5:
                display();
                break;
            case 6:
                queuesize();
                break;
            case 7:
                exit(0);
            default:
                printf("\nINVALID INPUT\n");
                break;
        }
    }
    return 0;
}
