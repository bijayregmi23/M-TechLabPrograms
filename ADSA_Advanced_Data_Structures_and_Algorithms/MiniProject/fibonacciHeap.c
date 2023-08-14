#include<stdio.h>
#include<stdlib.h>

#define INFINITY 999
#define NEGATIVE_INFINITY -999


// Structure Of Node
typedef struct Node{
    int key, degree, marked;
    struct Node *parent, *child, *left, *right;
}node;

// Structure Of Heap
typedef struct Heap{
    node *hMin;
    int nH, tH, mH, phiH;
    // nH -> Total # of Nodes in Fibonacci Heap
    // tH -> Total # of Rooted Trees
    // mH -> Total # of Marked Nodes
    // phiH -> Potential Function of Fibonacci Heap
}fheap;

// Structure Of DegreePointerArray used in ExtrackMin
typedef struct DegreePointerArray{
    node *pointsTo;
    int isPointing;
}pointerArray;

// It finds the potential funcion
int potentialFunction(int tH, int mH){
    int phi = tH + (2*mH);
    return phi;
}

// Initializes Empty Heap
fheap* initializeHeap(){
    fheap *newHeap = (fheap *)malloc(sizeof(fheap));
    newHeap->hMin = NULL;
    newHeap->nH = 0;
    newHeap->tH = 0;
    newHeap->mH = 0;
    newHeap->phiH = 0;
    return newHeap;
}

// Creates Node for given key
node* createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->degree = 0;
    newNode->key = data;
    newNode->marked = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->child = NULL;
    return newNode;
}

// Inserts node to the Heap
void insertion(fheap *h, int data){
    node *newNode = createNode(data);
    if(h->hMin == NULL){
        // Changes in node
        newNode->left = newNode;
        newNode->right = newNode;
        // Changes in heap(h)
        h->hMin = newNode;
        h->nH += 1;
        h->tH += 1;
        h->phiH = potentialFunction(h->tH, h->mH);
        return;
    }
    // Changes in node
    newNode->left = h->hMin->left;
    newNode->right = h->hMin;
    h->hMin->left->right = newNode;
    h->hMin->left = newNode;
    // changes in heap(h)
    if(h->hMin->key > newNode->key)
        h->hMin = newNode;
    h->nH += 1;
    h->tH += 1;
    h->phiH = potentialFunction(h->tH, h->mH);
}

// Finds Root Node with Maximum Degree
int findMaxDegree(fheap *h){
    int degree = h->hMin->degree;
    node *temp = h->hMin->right;
    while (temp != h->hMin){
        if(degree < temp->degree)
            degree = temp->degree;
        temp = temp->right;
    }
    return degree;
}

// Deletes hMin and Finds new hMin
void extractMin(fheap *h){
    if(h->hMin == NULL){
        printf("\n\nERROR ! Heap is Empty.");
        return;
    }
    // Heap has only a single node
    if(h->nH == 1){
        node *temp = h->hMin;
        h->hMin = NULL;
        free(temp);
        h->nH = 0;
        h->tH = 0;
        h->mH = 0;
        h->phiH = 0;
        return;
    }
    // Heap has more than one node
    else if(h->nH > 1){
        node *temp = h->hMin;
        // if hMin has a child
        if(h->hMin->child){
            // Heap has single rooted tree
            if(h->tH == 1){
                h->hMin->child->parent = NULL;
                h->hMin = h->hMin->child;
            }
            // Heap has more than one rooted tree
            else{
                h->hMin->child->left->right = h->hMin->right;
                h->hMin->right->left = h->hMin->child->left;
                h->hMin->child->left = h->hMin->left;
                h->hMin->left->right = h->hMin->child;
                h->hMin->child->parent = NULL;            
                h->hMin = h->hMin->right;
            }
            h->tH -= 1;
            h->tH += temp->degree;
        }
        // if hMin does not have a child
        else{
            h->hMin->left->right = h->hMin->right;
            h->hMin->right->left = h->hMin->left;
            h->hMin = h->hMin->right;
            h->tH -= 1;
        }
        free(temp);
        h->nH -= 1;
        h->phiH = potentialFunction(h->tH, h->mH);
    }
    // Creating DegreePointer
    int maxDegree = findMaxDegree(h);
    pointerArray *A[10];
    int i;
    for(i=0; i<=maxDegree; i++){
        A[i] = (pointerArray*)malloc(sizeof(pointerArray));
        A[i]->isPointing = 0;
        A[i]->pointsTo = NULL;
    }
    // node *wx = h->hMin;
    // node *end = h->hMin;

    
}

// Displays Fibonacci Heap
void display(fheap *h){ 
    printf("\n\nRoot Node List : %d",h->hMin->key);
    node *temp = h->hMin->right;
    while (temp != h->hMin){
        printf(" <-----> %d",temp->key);
        temp = temp->right;
    }
    
}

int main(){
    fheap *h = initializeHeap();

    int n = 7;
    int a[] = {4,2,3,1,6,5,7};

    // for(int i=0; i<n; i++)
        // insertion( h, a[i]);
    insertion(h,10);
    // insertion(h,15);
    node *newNode = createNode(20);
    newNode->left = newNode;
    newNode->right = newNode;
    newNode->parent = h->hMin;
    h->hMin->child = newNode;
    h->nH += 1;

    extractMin(h);
    display(h);

    return 0;
}

