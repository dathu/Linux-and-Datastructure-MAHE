#include<stdio.h>
#include<stdlib.h>


int top=-1;
char ch;

void push(int [] ,int );
void pop(int []);
void display(int []);
void peek();

int main()
{
    int choice=0,n;
    printf("\n--STACK IMPLEMENTATION USING ARRAYS--\n");
    printf("\nEnter the total elements in the stack : ");
    scanf("%d",&n);
    int stack[n];
    while(choice<5)
    {
        system("cls");
        printf("\n--STACK IMPLEMENTATION USING ARRAYS--\n");
        printf("\n1-> PUSH Element");
        printf("\n2-> POP Element");
        printf("\n3-> DISPLAY Stack");
        printf("\n4-> PEEK");
        printf("\n5-> EXIT\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(stack,n); break;
            case 2: pop(stack);break;
            case 3: display(stack); break;
            case 4: peek(stack); break;
            default: printf("\nProgram Ended\n"); printf("\nThankyou!"); break;
        }
    }
    return 0;
}

void peek(int stack[])
{
    if(top==-1)
    {
        printf("\nThe Stack is empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        printf("\nThe TOP Element of the Stack is : %d\n",stack[top]);
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
}
void display(int stack[])
{
    if(top==-1)
    {
        printf("\nThe Stack is empty\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        int i;
        printf("\nDisplaying the Stack\n");
        for(i=top;i>=0;i--)
        {
            printf("\n%4d",stack[i]);
        }
        printf("\n\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }    
}
void pop(int stack[])
{
    int ele;
    printf("\nPoping Operation\n");
    if(top==-1)
    {
        printf("\n--STACK UNDERFLOW--");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        printf("\nElement deleted is : %d",stack[top]);
        top--;
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
}
void push(int stack[],int n)
{
    printf("\nPushing Operation\n");
    if(top==n-1)
    {
        printf("\n--STACK OVERFLOW--\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        top++;
        printf("\nEnter the data : ");
        scanf("%d",&stack[top]);
        printf("\nData inserted successfully!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
}
