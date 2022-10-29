#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL,*temp,*newnode;

char ch;

void push();
void pop();
void display();
void peek();

int main()
{
    int choice=0;
    while(choice<5)
    {
        system("cls");
        printf("\n--STACK USING LINKED LIST--\n");
        printf("\n1-> PUSH Element");
        printf("\n2-> POP Element");
        printf("\n3-> Display Stack");
        printf("\n4-> PEEK");
        printf("\n5-> EXIT\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)      //Switch case statement
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peek(); break;
            default: printf("\nProgram Ended!\n"); printf("\nThankyou!"); break;
        }
    }
    return 0;
}
//Performing Peek Operation
void peek()
{
    if(top==NULL)
    {
        printf("\nThe Stack is Empty!\n");
    }
    else
    {
        printf("\nThe TOP Element of the Stack is : %d\n",top->data);
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

//Poping the top node out of the Stack
void pop()
{
    temp=top;
    if(temp==NULL)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
        printf("\nElement deleted is : %d\n",top->data);
        top=top->next;
        temp->next=NULL;
        free(temp);
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

//Displaying the Stack
void display()
{
    temp=top;
    if(temp==NULL)              //Checking whether the Stack is empty
    {
        printf("\nThe Stack is Empty!\n");
    }
    else
    {
        printf("\nDisplaying the Stack\n");
        while(temp!=NULL)
        {
            printf("\n%5d",temp->data);
            temp=temp->next;                //Traversing the nodes
        }
    }
    printf("\n\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

//Pushing the new node on top of the stack
void push()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(top==NULL)               //Checking whether Stack is empty or not
    {
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=top;
        top=newnode;
    }
    printf("\n Element inserted successfully!\n");
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;                //Returning to Main Function
}
