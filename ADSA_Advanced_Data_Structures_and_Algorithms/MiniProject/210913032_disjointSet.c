#include<stdio.h>
#include<stdlib.h>

#define MAX 20

// Structure of Edge
typedef struct Edge{
    char source, destination;
}edge;

// Structure of Node
typedef struct Node{
    char data;
    struct Node *next;
}node;

// Structure of Set
typedef struct Set{
    node *head;
    int cardinal;
}set;

// Finds whether key(int) is present in s(set) or not
node* findData(set *s, char key){
    if(s->cardinal == 0)
        return NULL;
    node *temp = s->head;
    while(temp){
        if(temp->data == key)
            return temp;
        temp=temp->next;
    }
    return NULL;
}

// Adds Item n to the Set s
void addItem(set *s, int data){
    node *n = (node *)malloc(sizeof(node));
    n->next = NULL;
    n->data = data;
    if(s->head == NULL){
        s->head = n;
        s->cardinal += 1;
        return;
    }
    node *temp = s->head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
    s->cardinal += 1;
}

// Union of Set s1 and s2
set * unionOperation(set *s1, set *s2){
    if(s2->cardinal == 0)
        return s1;
    node *temp2 = s2->head;
    // Traversing through Set 1
    while(temp2){
        if(findData(s1,temp2->data) == NULL)
            addItem(s1,temp2->data);
        temp2 = temp2->next;
    }
    return s1;
}

// Make a new set for given Vertex
set * makeSet(char data){
    set *s = (set*)malloc(sizeof(set));
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    s->head = newNode;
    s->cardinal = 1;
    return s;
}

// Returns set s from allSets[MAX]
int findSet(set *allSets[MAX], int noOfVertices, char key){
    for (int i=0; i<noOfVertices; i++){
        if(findData(allSets[i],key))
            return i;
    }
    return -1;   
}

// Prints set
void printSet(set *s){
    if(s->cardinal == 0){
        printf(" {} ");
        return;
    }
    node *temp = s->head->next;
    printf(" { %c",s->head->data);
    while(temp){
        printf(", %c", temp->data);
        temp=temp->next;
    }
    printf(" } ");
}

// Makes s(set) Empty
void makeEmpty(set *s){
    node *temp = s->head, *temp1;
    while(temp){
        temp1=temp;
        temp = temp->next;
        free(temp1);
    }
    s->cardinal = 0;
    s->head = NULL;
}

// Finds index of the vertes form all vertices
int findIndex(char *vertices, int n, char key){
    for(int i=0; i<n; i++){
        if(key == vertices[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    // Taking input for vertices and edges
    int noOfVertices = 10, noOfEdges = 6, i, j;
    printf("\nEnter total number of Vertex : ");
    scanf("%d",&noOfVertices);
    char *vertices = (char*)malloc(noOfVertices * sizeof(char));
    set *allSets[MAX];
    printf("\nEnter all Vertices : ");
    for(i=0; i<noOfVertices; i++){
        scanf("%s",&vertices[i]);
        allSets[i] = makeSet(vertices[i]);
    }
    printf("\nEnter total number of Edge : ");
    scanf("%d",&noOfEdges);
    edge *edges = (edge*)malloc(noOfEdges * sizeof(edge));
    printf("\nEnter all Edges (Source and Destination):\n");
    for(i=0; i<noOfEdges; i++){
        scanf("%s",&edges[i].source);
        scanf("%s",&edges[i].destination);
    }

    // Printing vertices and edges
    printf("\n\nVertices(V) : %c",vertices[0]);
    for(i=1; i<noOfVertices; i++)
        printf(", %c",vertices[i]);
    printf("\nEdges(E) : (%c,%c)", edges[0].source, edges[0].destination);
    for(i=1; i<noOfEdges; i++){
        printf(", (%c, %c)", edges[i].source, edges[i].destination);
    }

    int sIndex, dIndex;
    // Looping through all the edges
    for(i=0; i<noOfEdges; i++){
        sIndex = findIndex(vertices, noOfVertices, edges[i].source);
        dIndex = findIndex(vertices, noOfVertices, edges[i].destination);
        if(allSets[sIndex]->cardinal == 0){
            sIndex = findSet(allSets, noOfVertices, edges[i].source);
        }
        if(allSets[dIndex]->cardinal ==0){
            dIndex = findSet(allSets, noOfVertices, edges[i].destination);
        }
        unionOperation(allSets[sIndex], allSets[dIndex]);
        if(sIndex != dIndex)
            makeEmpty(allSets[dIndex]);
    }

    // Printing all non empty sets
    printf("\n\n\nDISJOINT SETS : ");
    for(i=0; i<noOfVertices; i++){
        if(allSets[i]->cardinal != 0){
            printSet(allSets[i]);
            printf(",");
        }
    }
    printf("\n\n");
    return 0;
}
