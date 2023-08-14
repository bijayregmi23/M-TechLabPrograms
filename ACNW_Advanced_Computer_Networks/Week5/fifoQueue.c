#include<stdio.h>
#include<stdlib.h>

# define MAX 3

// Structure of Queue
typedef struct Queue{
    int data;
    int priority;
    struct Queue *left, *right;
}queue;

queue *head = NULL;
queue *tail = NULL;
queue *minPriority = NULL;
int queueSize = 0;

// Creates a new Node
queue* createNode(int data, int priority){
    queue *newNode = (queue*)malloc(sizeof(queue));
    newNode->data = data;
    newNode->priority = priority;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Checks Whether Queue is Empty Or Not
int isQueueEmpty(){
    if(head == NULL && tail == NULL){
        printf("\nERROR ! Queue is Empty.");
        return 1;
    }
    return 0;
}
// Finds next Min Priority
queue* findMinPriority(){
    if(head != NULL && tail != NULL){
        queue *temp = tail->right, *minPriority=tail;
        while (temp){
            if(minPriority->priority > temp->priority)
                minPriority = temp;
            temp=temp->right;
        }
        return minPriority;
    }
    return NULL;
}
// Discard min priority and adds upcoming
void priorityDiscardPolicy(queue *newNode ){
    // Removing Min Priority
    if(minPriority->left)
        minPriority->left->right = minPriority->right;
    if(minPriority->right)
        minPriority->right->left = minPriority->left;
    printf("\nPacket %d(%d) is removed, Since it has got low priority.",minPriority->data,minPriority->priority);
    queue *temp = minPriority;
    free(temp);
    minPriority = findMinPriority();
    // Adding NewNode to tail
    if(minPriority->priority > newNode->priority)
        minPriority = newNode;
    newNode->right = tail;
    tail->left = newNode;
    tail = tail->left;
    printf("\nPacket %d(%d) is added in Queue.",tail->data,tail->priority);
}
// Enter value in tail
void enqueue(int data, int priority){
    queue *newNode = createNode(data,priority);
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
        minPriority = newNode;
        queueSize ++;
        printf("\nPacket %d(%d) is first data in Queue.",tail->data,tail->priority);
        return;
    }
    if(queueSize == MAX){
        int ch;
        printf("\n\nQUEUE OVERFLOW!!\nPACKET DISCARD POLICY\n1. Priority\n2. Tail Drop\nEnter Choice : ");
        scanf("%d",&ch);
        if(ch==1){
            priorityDiscardPolicy(newNode);
            return;
        }
        else if(ch == 2){
            printf("\nPacket %d(%d) has dropped, since its on Tail.",newNode->data,newNode->priority);
            free(newNode);
            return;
        }
    }
    if(minPriority->priority > newNode->priority)
        minPriority = newNode;
    newNode->right = tail;
    tail->left = newNode;
    tail = tail->left;
    queueSize ++;
    printf("\nPacket %d(%d) is added in Queue.",tail->data,tail->priority);
}
// Delete value from head
void dequeue(){
    if(!isQueueEmpty()){
        queue *temp = head;
        if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->left;
            head->right = NULL;
        }
        if(minPriority == temp )
            minPriority = findMinPriority();
        printf("\nPacket %d(%d) is removed !",temp->data,temp->priority);
        queueSize -- ;
        free(temp);
    }
}
// Displays queue
void display(){
    queue *temp=tail;
    printf("\n\nQUEUE : ");
    while (temp){
        printf("%d(%d)\t",temp->data,temp->priority);
        temp = temp->right;
    }
    printf("\nQueueSize : %d",queueSize);
}

int main(){
    printf("\n\n");
    int ch=0, data, priority;
    printf("\nQUEUE PACKET SCHEDULING\n\n");
    while(ch != 5){
        printf("\n\n1. Insert Packet\n2. Remove Packet\n3. Display all Packets in Queue\n4. Exit\n\nEnter Your Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            printf("\nEnter Packet Number and its Priority : ");
            scanf("%d", &data);
            scanf("%d", &priority);
            enqueue(data, priority);
        }
        else if(ch==2)
            dequeue();
        
        else if(ch ==3)
            display();
        
        else if(ch == 4)
            break;
        else
            printf("\n\nERROR ! Invalid Input.");
    }

    printf("\n\n");
    return 0;
}