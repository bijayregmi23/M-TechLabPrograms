#include<stdio.h>
#include<stdlib.h>

typedef struct Heap{
    int degree,key;
    struct Heap *parent, *lchild, *right;
}bheap;

bheap *head = NULL;

// Creates a new Node
bheap* createNode(int data){
    bheap *newNode = (bheap *)malloc(sizeof(bheap));
    newNode->degree = 0;
    newNode->key = data;
    newNode->parent = NULL;
    newNode->lchild = NULL;
    newNode->right = NULL;
    return newNode;
}

void combineHeaps(bheap *node1, bheap *node2){  
    bheap *n1,*n2;
    int degree = node1->degree;
    // printf("\nNode1 : %d\tDegree : %d",node1->key, node1->degree);
    // printf("\nNode2 : %d\tDegree : %d",node2->key, node2->degree);

    node2->parent = node1;
    node2->right = NULL;

    n1 = node1->lchild;  //Previous Child Of Node 1
    
    node1->lchild = node2;
    node1->degree++;
    // bheap *node = node1;

    if(degree == 0)
        return;

    for(int i=0; i<degree; i++){
        n2 = node2;
        while(n2->right)
            n2=n2->right;
        n2->right =n1;
        n1 = n1->lchild;
        node2 = node2->lchild;
    }
    return;
}

// Union Operation between newHeap and head
void unionOperaion(bheap * newNode){
    if(head==NULL){
        head = newNode;
        return;
    }

    // Merging newNode(New Binomial Heap) to head(Old Binomial Heap) 
    if(newNode){
        bheap *t1=head , *t2=newNode, *temp1, *temp2;
        // printf("\nt1 : %d",t1->key);
        // printf("\nt2 : %d",newNode->key);
        while(t2){
            if(t1->degree < t2 -> degree){
                t1 = t1->right;
            }
            else if(t1->degree > t2 -> degree){
                temp1 = head;
                if(temp1->degree < t1->degree){
                    while(temp1->right->degree < t1->degree)
                        temp1 = temp1->right;
                }
                temp2 = t2->right;
                if(temp1 == head){
                    head = t2;
                    t2->right = t1;
                }
                else
                    temp1->right = t2;
                t2 = temp2;
            }
            else{
                temp1 = t1->right;
                temp2 = t2->right;
                
                t1->right = t2;
                t2 ->right = temp1;

                t1 = temp1;
                t2=temp2;
            }
        }
    }

    // Union Of Binomial Heap With Same Degree
    bheap *prevX = NULL,
    *x = head,
    *nextX = head->right;

    while (nextX){

        // printf("\nWhile Loop  :   ");
        // bheap *temp=head;
        // while(temp){
        //     printf("%d\t",temp->key); 
        //     temp = temp->right;
        // }  
        // Defining prev[X]
        // if(x==head->right)
        //     prevX = head;

        // CASE 1 
        if(x->degree != nextX->degree){
            // prevX = prevX->right;
            x = x->right;
            nextX = nextX->right;
            continue;
        }
        // CASE 2
        if(x->degree == nextX->degree   && nextX->right &&  nextX->degree == nextX->right->degree){
            // prevX = prevX->right;
            x = x->right;
            nextX = nextX->right;
            continue;
        }

        // CASE 3 and CASE 4
        if(nextX->right){
            if(x->degree == nextX->degree   &&  nextX->right &&  nextX->degree != nextX->right->degree){
                bheap *node1, *node2;
                // CASE 3
                if(nextX->key >= x->key){
                    node1 = x;
                    node2 = nextX;

                    nextX = nextX->right;
                    node1->right = nextX;

                    // printf("\nCASE 3.1   Node1 : %d\tDegree : %d",node1->key, node1->degree);
                    // printf("\nCASE 3.1   Node2 : %d\tDegree : %d",node2->key, node2->degree);
                    combineHeaps(node1,node2);
                    // prevX = prevX->right;
                }
                // CASE 4
                else{
                    node1 = nextX;
                    node2 = x;
                    if(head == node2)
                        head = node1;
                    nextX = nextX->right;
                    x = x->right;
                    // printf("\nCASE 4.1   Node1 : %d\tDegree : %d",node1->key, node1->degree);
                    // printf("\nCASE 4.1   Node2 : %d\tDegree : %d",node2->key, node2->degree);
                    combineHeaps(node1,node2);
                    // prevX = prevX->right;
                }
                // prevX = prevX->right;
                continue;
            }
        }
        else{
            if(x->degree == nextX->degree){
                bheap *node1, *node2;

                // CASE 3
                if(nextX->key >= x->key){
                    node1 = x;
                    node2 = nextX;

                    nextX = nextX->right;
                    node1->right = nextX;

                    // printf("\nCASE 3.2   Node1 : %d\tDegree : %d",node1->key, node1->degree);
                    // printf("\nCASE 3.2   Node2 : %d\tDegree : %d",node2->key, node2->degree);
                    
                    combineHeaps(node1,node2);
                }
                // CASE 4
                else{
                    node1 = nextX;
                    node2 = x;
                    if(head == node2)
                        head = node1;
                    nextX = nextX->right;
                    x = x->right;
                    
                    // printf("\nCASE 4.2   Node1 : %d\tDegree : %d",node1->key, node1->degree);
                    // printf("\nCASE 4.2   Node2 : %d\tDegree : %d",node2->key, node2->degree);
                    combineHeaps(node1,node2);
                }
                // prevX = prevX->right;
                continue;
            }
        }
        x = x->right;
        nextX = nextX->right;
    }
}


// Displays Binomal Heap
void display(){
    bheap *temp, *level, *root = head;
    int degree;
    printf("\nBINOMIAL HEAP\n");
    while(root){
        level = root;
        degree = level->degree;

        printf("\nBinomial Tree : %d(%d)",root->key,root->degree);
        for(int i=0; i<=degree ; i++){
            temp = level;
            printf("\n");
            while(temp){
                if(i==0){
                    printf("------->%d(%d)",temp->key,temp->degree);
                    break;
                }
                else{
                    printf("\t%d(%d)",temp->key,temp->degree);
                    temp = temp->right;
                }
            }
            level=level->lchild;
        }
        printf("\n");
        root = root->right;
    }
}

// Creates a new Binomial Heap
void insertion(int data){
    bheap *newHeap = createNode(data);
    unionOperaion(newHeap);
}


int main(){
    insertion(40);
    insertion(30);
    insertion(10);
    insertion(20);
    insertion(5);
    insertion(7);
    insertion(31);
    insertion(9);

    insertion(45);
    insertion(55);
    insertion(100);
    display();

    // bheap *temp=head;
    // temp=head->lchild->lchild->right;
    // printf("\n\nKey:%d\tDegree:%d",temp->key,temp->degree); 


    printf("\n");
    return 0;
}