#include<stdio.h>
#include<stdlib.h>

typedef struct Heap{
    int degree,key;
    struct Heap *parent, *lchild, *right;
}bheap;

bheap *head = NULL;
int cost,count;

// Creates a new Node
bheap* createNode(int data){
    bheap *newNode = (bheap *)malloc(sizeof(bheap));
    newNode->degree = 0;
    newNode->key = data;
    newNode->parent = NULL;
    newNode->lchild = NULL;
    newNode->right = NULL;

    cost += 6;
    count += 1;

    return newNode;
}

void combineHeaps(bheap *node1, bheap *node2){
    bheap *n1,*n2;
    int degree = node1->degree;


    node2->parent = node1;
    node2->right = NULL;

    n1 = node1->lchild;  //Previous Child Of Node 1
    
    node1->lchild = node2;
    node1->degree++;
    // bheap *node = node1;
    
    cost += 5;
    count += 6;

    if(degree == 0)
        return;

    for(int i=0; i<degree; i++){
        n2 = node2;
        while(n2->right){
            n2=n2->right;
            cost += 1;
            count += 1;
        }
        n2->right =n1;
        n1 = n1->lchild;
        node2 = node2->lchild;
        cost += 4;
        count += 1;
    }
    return;
}

// Union Operation between newHeap and head
void unionOperaion(bheap * newNode){
    int localCost = 0, localCount = 0;
    if(head==NULL){
        head = newNode;
        cost += 1;
        count += 1;
        return;
    }

    // Merging newNode(New Binomial Heap) to head(Old Binomial Heap) 
    if(newNode){
        bheap *t1=head , *t2=newNode, *temp1, *temp2;
        while(t2){
            if(t1->degree < t2 -> degree){
                t1 = t1->right;
                localCost += 1;
                localCount += 1;
            }
            else if(t1->degree > t2 -> degree){
                temp1 = head;
                if(temp1->degree < t1->degree){
                    while(temp1->right->degree < t1->degree){
                        temp1 = temp1->right;
                        localCost += 1;
                        localCount += 1;
                    }
                }
                temp2 = t2->right;
                if(temp1 == head){
                    head = t2;
                    t2->right = t1;
                    localCost += 2;
                    localCount += 1;
                }
                else{
                    temp1->right = t2;
                    localCost += 1;
                    localCount += 1;
                }
                t2 = temp2;
                localCost += 3;
                localCount += 1;
            }
            else{
                temp1 = t1->right;
                temp2 = t2->right;
                
                t1->right = t2;
                t2 ->right = temp1;

                t1 = temp1;
                t2=temp2;
                localCost += 6;
                localCount += 1;
            }
        }
    }

    // Union Of Binomial Heap With Same Degree
    bheap *prevX = NULL,
    *x = head,
    *nextX = head->right;

    while (nextX){

        // CASE 1 
        if(x->degree != nextX->degree){
            x = x->right;
            nextX = nextX->right;
            localCost += 2;
            localCount += 1;
            continue;
        }
        // CASE 2
        if(x->degree == nextX->degree   && nextX->right &&  nextX->degree == nextX->right->degree){
            x = x->right;
            nextX = nextX->right;
            localCost += 2;
            localCount += 1;
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

                    localCost += 4;
                    localCount += 1;

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

                    localCost += 4;
                    localCount += 1;

                    combineHeaps(node1,node2);
                }
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

                    localCost += 4;
                    localCount += 1;
                    
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

                    localCost += 4;
                    localCount += 1;

                    combineHeaps(node1,node2);
                }

                continue;
            }
        }
        x = x->right;
        nextX = nextX->right;
        localCost += 2;
        localCount += 1;
    }
    cost += localCost;
    count += localCount;
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
    cost = 0;
    count = 0;
    int i, n = 10;
    int A[] = {35,25,5,15,1,26,4,40,60,200};
    for(i=0; i<n; i++){
        insertion(A[i]);
        printf("\nINSERT(%d)\t|\t\tCount : %d\tAmortized Cost : %d",A[i],count,cost);
    }
    printf("\n\n\n");

    display();

    printf("\n\n");
    return 0;
}