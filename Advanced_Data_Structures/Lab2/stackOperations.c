#include <stdio.h>
#include <stdlib.h>
int top,s[10];
int item,i,n,amortized_cost,count=0,cost=0,stacksize=1;

void push(int item)
{
        if(top==(stacksize-1))
        {
                printf("\nStack overflow !");
                return;
        }
        count++;
        stacksize+=1;
        cost++;
        top+=1;
        s[top]=item;
        printf("\nTotal cost: %d",cost);
}

void pop()
{
        if(top==-1)
        {
                printf("\nStack is empty !");
                return;
        }
        cost++;
        count++;
        item=s[top--];
        printf("\nItem Popped is %d",item);
        printf("\nTotal cost : %d",cost);
}

void multipop(int n)
{
        if(top==-1)
        {
                printf("\nStack is empty");
                return;
        }
        for(i=0;i<n;i++)
        {
                cost++;
                count++;
                item=s[top--];
                printf("\nItem popped is %d",item);
                printf("\nTotal cost : %d",cost);
        }
}

void display()
{
        if(top==-1)
        {
                printf("\nStack is empty !");
                return;
        }
        printf("\nStack Items are : ");
        for(i=0;i<=top;i++) printf("%d\t",s[i]);

        printf("\nThe amortized cost for %d operation is %d",count,cost);
}

int main()
{
        printf("\nStudent Name : BIJAY REGMI\nRoll Number : 210913032\n\nSTACK OPERATIONS\n");
        int choice = -1,n;
        top = -1;
        printf("\nSTACK OPERATIONS :");

        while(choice != 5)
        {
                printf("\n\n1. Push \n2. Pop \n3. Multipop \n4. Display\n5. Exit\n");
                printf("\nEnter choice : ");
                scanf("%d",&choice);

                switch(choice){
                case 1: printf("\nEnter item to be pushed : ");
                        scanf("%d",&item);
                        push(item);
                        break;

                case 2: pop();
                        break;

                case 3: printf("\nEnter the number of item : ");
                        scanf("%d",&n);
                        multipop(n);
                        break;

                case 4: display();
                        break;

                case 5: break;

                default:printf("\nInvalid Input");
                        break;
                }
        }
        printf("\n");
        return 0;
}
