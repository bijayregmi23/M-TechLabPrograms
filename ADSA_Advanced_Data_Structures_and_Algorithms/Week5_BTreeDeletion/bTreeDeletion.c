#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 2

int count,cost;

struct btreeNode
{
    int val[MAX + 1], count;
    struct btreeNode *link[MAX + 1];
};

struct btreeNode *root;

/* creating new node */
struct btreeNode *createNode(int val, struct btreeNode *child)
{
    struct btreeNode *newNode;
    newNode = (struct btreeNode *)malloc(sizeof(struct btreeNode));
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

/* Places the value in appropriate position */
void addValToNode(int val, int pos, struct btreeNode *node,
                  struct btreeNode *child)
{
    int j = node->count;
    while (j > pos)
    {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}

/* split the node */
void splitNode(int val, int *pval, int pos, struct btreeNode *node,
               struct btreeNode *child, struct btreeNode **newNode)
{
    int median, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct btreeNode *)malloc(sizeof(struct btreeNode));
    j = median + 1;
    while (j <= MAX)
    {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN)
    {
        addValToNode(val, pos, node, child);
    }
    else
    {
        addValToNode(val, pos - median, *newNode, child);
    }
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

/* sets the value val in the node */
int setValueInNode(int val, int *pval,
                   struct btreeNode *node, struct btreeNode **child)
{

    int pos;
    if (!node)
    {
        *pval = val;
        *child = NULL;
        return 1;
    }

    if (val < node->val[1])
    {
        pos = 0;
    }
    else
    {
        for (pos = node->count;
             (val < node->val[pos] && pos > 1); pos--)
            ;
        if (val == node->val[pos])
        {
            printf("Duplicates not allowed\n");
            return 0;
        }
    }
    if (setValueInNode(val, pval, node->link[pos], child))
    {
        if (node->count < MAX)
        {
            addValToNode(*pval, pos, node, *child);
        }
        else
        {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

/* insert val in B-Tree */
void insertion(int val)
{
    int flag, i;
    struct btreeNode *child;

    flag = setValueInNode(val, &i, root, &child);
    if (flag)
        root = createNode(i, child);
}

void doRightShift(struct btreeNode *myNode, int pos)
{
    int localCost = 0, localCount = 0;
    struct btreeNode *x = myNode->link[pos];
    int j = x->count;

    while (j > 0)
    {
        x->val[j + 1] = x->val[j];
        x->link[j + 1] = x->link[j];
        localCost += 2;
        localCount += 1;
    }
    x->val[1] = myNode->val[pos];
    x->link[1] = x->link[0];
    x->count++;

    x = myNode->link[pos - 1];
    myNode->val[pos] = x->val[x->count];
    myNode->link[pos] = x->link[x->count];
    x->count--;
    
    localCost += 4;
    localCount += 1;
    cost += localCost;
    count += localCount;
    return;
}

/* shifts value from parent to left child */
void doLeftShift(struct btreeNode *myNode, int pos)
{
    int localCost = 0, localCount = 0;
    int j = 1;
    struct btreeNode *x = myNode->link[pos - 1];

    x->count++;
    x->val[x->count] = myNode->val[pos];
    x->link[x->count] = myNode->link[pos]->link[0];

    x = myNode->link[pos];
    myNode->val[pos] = x->val[1];
    x->link[0] = x->link[1];
    x->count--;

    localCost += 4;
    localCount += 1;

    while (j <= x->count)
    {
        x->val[j] = x->val[j + 1];
        x->link[j] = x->link[j + 1];
        j++;
        localCost += 2;
        localCount += 1;
    }
    cost += localCost;
    count += localCount;
    return;
}

/* merge nodes */
void mergeNodes(struct btreeNode *myNode, int pos)
{
    int localCost = 0, localCount = 0;
    int j = 1;
    struct btreeNode *x1 = myNode->link[pos], *x2 = myNode->link[pos - 1];

    x2->count++;
    x2->val[x2->count] = myNode->val[pos];
    x2->link[x2->count] = myNode->link[0];

    while (j <= x1->count)
    {
        x2->count++;
        x2->val[x2->count] = x1->val[j];
        x2->link[x2->count] = x1->link[j];
        j++;
        localCost += 2;
        localCount += 1;
    }

    j = pos;
    while (j < myNode->count)
    {
        myNode->val[j] = myNode->val[j + 1];
        myNode->link[j] = myNode->link[j + 1];
        j++;
        localCost += 2;
        localCount += 1;
    }
    myNode->count--;
    free(x1);
}

/* adjusts the given node */
void adjustNode(struct btreeNode *myNode, int pos)
{
    if (!pos)
    {
        if (myNode->link[1]->count > MIN)
        {
            doLeftShift(myNode, 1);
        }
        else
        {
            mergeNodes(myNode, 1);
        }
    }
    else
    {
        if (myNode->count != pos)
        {
            if (myNode->link[pos - 1]->count > MIN)
            {
                doRightShift(myNode, pos);
            }
            else
            {
                if (myNode->link[pos + 1]->count > MIN)
                {
                    doLeftShift(myNode, pos + 1);
                }
                else
                {
                    mergeNodes(myNode, pos);
                }
            }
        }
        else
        {
            if (myNode->link[pos - 1]->count > MIN)
                doRightShift(myNode, pos);
            else
                mergeNodes(myNode, pos);
        }
    }
}

/*int findDepth(struct btreeNode *myNode, int val)
 {
    // Base case
    if (root == NULL)
        return -1;
    int dist = -1;

    // Check if x is current node=
    if ((root->data == x)|| (dist = findDepth(root->left, x)) >= 0|| (dist = findDepth(root->right, x)) >= 0)
        return dist + 1;

    return dist;
 }*/

/* B-Tree Traversal */
void traversal(struct btreeNode *myNode)
{
    int i;
    if (myNode)
    {
        for (i = 0; i < myNode->count; i++)
        {
            traversal(myNode->link[i]);

            printf("%d ", myNode->val[i + 1]);
        }
        traversal(myNode->link[i]);
    }
}

void searching(int val, int *pos, struct btreeNode *myNode)
{
    if (!myNode)
    {
        return;
    }

    if (val < myNode->val[1])
    {
        *pos = 0;
    }
    else
    {
        for (*pos = myNode->count;
             (val < myNode->val[*pos] && *pos > 1); (*pos)--)
            ;
        if (val == myNode->val[*pos])
        {

            printf("\nGiven data %d is present in B-Tree\n", val);
            return;
        }
    }
    searching(val, pos, myNode->link[*pos]);
    return;
}

/* copy successor for the value to be deleted */
void copySuccessor(struct btreeNode *myNode, int pos)
{
    int localCost = 0, localCount = 0;
    struct btreeNode *dummy;
    dummy = myNode->link[pos];

    for (; dummy->link[0] != NULL;){
        dummy = dummy->link[0];
        localCost++;
        localCount++;
    }
    myNode->val[pos] = dummy->val[1];
    localCost++;
    localCount++;
    cost += localCost;
    count += localCount;
}

/* removes the value from the given node and rearrange values */
void removeVal(struct btreeNode *myNode, int pos)
{
    int localCost = 0, localCount = 0;
    int i = pos + 1;
    while (i <= myNode->count)
    {
        myNode->val[i - 1] = myNode->val[i];
        myNode->link[i - 1] = myNode->link[i];
        localCost += 2;
        localCount++;
        i++;
    }
    myNode->count--;
    cost += localCost;
    count += localCount;
}

/* delete val from the node */
int delValFromNode(int val, struct btreeNode *myNode)
{
    int localCost = 0, localCount=0;
    int pos, flag = 0;
    if (myNode)
    {
        if (val < myNode->val[1])
        {
            pos = 0;
            flag = 0;
        }
        else
        {
            for (pos = myNode->count;
                 (val < myNode->val[pos] && pos > 1); pos--)
                ;
            if (val == myNode->val[pos])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag)
        {
            if (myNode->link[pos - 1])
            {
                copySuccessor(myNode, pos);
                flag = delValFromNode(myNode->val[pos], myNode->link[pos]);
                localCost += 1;
                localCount += 1;
                if (flag == 0)
                {
                    printf("Given data is not present in B-Tree\n");
                }
            }
            else
            {
                removeVal(myNode, pos);
            }
        }
        else
        {
            flag = delValFromNode(val, myNode->link[pos]);
            localCost += 1;
            localCount += 1;
        }
        if (myNode->link[pos])
        {
            if (myNode->link[pos]->count < MIN)
                adjustNode(myNode, pos);
        }
    }
    cost += localCost;
    count += localCount;
    return flag;
}

/* delete val from B-tree */
void deletion(int val, struct btreeNode *myNode)
{
    int localCount = 0, localCost = 0;
    struct btreeNode *tmp;
    if (!delValFromNode(val, myNode))
    {
        printf("Given value is not present in B-Tree\n");
        return;
    }
    else
    {
        if (myNode->count == 0)
        {
            tmp = myNode;
            myNode = myNode->link[0];
            free(tmp);
            localCount += 1;
            localCost += 3;
            printf("%d deleted from the btree.\n", val);
        }
    }
    root = myNode;
    localCost += 1;
    cost += localCost;
    count += localCount;
    return;
}

int main()
{
 printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n");
    printf("\nB-TREE DELETION\n");

    int item, choice = 0;
    while(choice != 5){
        printf("\n1. Insert\n2. Traverse\n3. Search\n4. Delete\n5. Exit\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("\nEnter element : ");
                    scanf("%d",&item);
                    insertion(item);
                    break;
            case 2: traversal(root);
                    printf("\n");
                    break;
            case 3: printf("\nEnter element : ");
                    scanf("%d",&item);
                    searching(item,&choice,root);
                    break;
            case 4: printf("\nEnter element : ");
                    scanf("%d",&item);
                    deletion(item, root);
                    printf("\nThe amortized cost for %d operations is %d\n",count,cost);
                    break;
            case 5: exit(0);
                    break;
            default:printf("\nINVALID INPUT\n");
                    break;
            printf("\n");
        }
    }
    printf("\n");
}
