#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL,*temp,*newnode;

void insert();
void delete();
void display();
void reverse();
int count();
void check_palin();
void insertatfirst();
void insertatend();
void insertafternode();
void delnode();
void delfromend();
void delfromfront();


char ch;

int main()
{
    int choice=0,n;
    while(choice<7)
    {
        system("cls");
        printf("\n--Circular Linked List Implementation--\n");
        printf("\n--MAIN MENU--\n");
        printf("\n1-> Insert a node");
        printf("\n2-> Delete a node");
        printf("\n3-> Display the List");
        printf("\n4-> Reverse the List");
        printf("\n5-> Count Total nodes in the List");
        printf("\n6-> Check if List is Palindrome");
        printf("\n7-> Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: reverse(); break;
            case 5:
            {
                n=count();
                printf("\nThe Total no.of Nodes in the List is : %d\n",n);
                printf("\nPress any key to continue : ");
                scanf(" %c",&ch);
                break;
            }
            case 6: check_palin(); break;
            default: printf("\nProgram Ended!"); printf("\nThankyou!"); break;
        }
    }
    return 0;
}

void check_palin()
{
    if(head==NULL)
    {
        printf("\nThe List is empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    struct node *temp1=head,*temp2=tail;
    int flag=1,i,j,n,num;
    num=count();
    n=num/2;
    for(i=1;i<=n;i++)
    {
        if(temp1->data!=temp2->data)
        {
            flag=0;
            break;
        }
        if(i==n)
        {
            break;
        }
        temp1=temp1->next;
        temp2=head;
        num--;
        for(j=1;j<num;j++)
        {
            temp2=temp2->next;
        }
    }
    if(flag==1)
    {
        printf("\nThe List is Palindromic!\n");
    }
    else
    {
        printf("\nThe List is not Palindromic!\n");
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

void reverse()
{
    if(head==NULL)
    {
        printf("\nThe List is empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nReversing the List\n");
    struct node *currnode=head,*prevnode=tail,*nextnode=head;
    while(nextnode->next!=head)
    {
        nextnode=nextnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    currnode->next=prevnode;
    temp=head;
    head=tail;
    tail=temp;
    printf("\nList Reversed successfully!\n");
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

int count()
{
    int num=0;
    temp=head;
    if(temp==NULL)
    {
        return num=0;
    }
    while(temp->next!=head)
    {
        num++;
        temp=temp->next;
    }
    return num+1;
}

void delete()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--Deletion Operations--\n");
        printf("\n1-> Delete from Beginning");
        printf("\n2-> Delete from End");
        printf("\n3-> Delete particular node");
        printf("\n4-> Exit to Main Menu");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: delfromfront(); break;
            case 2: delfromend(); break;
            case 3: delnode(); break;
            default: return ;
        }
    }
    return ;
}

void delnode()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    int nodevalue;
    printf("\nEnter the value of node to delete : ");
    scanf("%d",&nodevalue);
    if(nodevalue==head->data)
    {
        delfromfront();
        return ;
    }
    if(nodevalue==tail->data)
    {
        delfromend();
        return ;
    }
    int flag=0;
    while(1)
    {
        if(temp->next->data==nodevalue)
        {
            flag=1;
            break;
        }
        if(temp->next==head)
        {
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nThe node is not present in the List\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        printf("\nElement to be deleted is : %d",temp->next->data);
        struct node *temp2;
        temp2=temp->next;
        temp->next=temp2->next;
        temp2->next=NULL;
        free(temp2);
        printf("\nElement deleted successfully!");
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
void delfromend()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nDeleting the Last Node");
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    tail->next=NULL;
    printf("\nNode deleted is : %d\n",tail->data);
    free(tail);
    temp->next=head;
    tail=temp;
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
void delfromfront()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nDeleting the front node\n");
    head=head->next;
    tail->next=head;
    temp->next=NULL;
    printf("\nNode deleted is : %d\n",temp->data);
    free(temp);
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!\n");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nDisplaying the Linked List\n");
    while(1)
    {
        if(temp->next==head)
        {
            printf("%d->HEAD",temp->data);
            break;
        }
        else
        {
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
    printf("\n\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}

void insert()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--Insertion Operations--\n");
        printf("\n1-> Insert at beginning");
        printf("\n2-> Insert at end");
        printf("\n3-> Insert after specific node");
        printf("\n4-> Return to Main Menu");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertatfirst(); break;
            case 2: insertatend(); break;
            case 3: insertafternode(); break;
            default: break;
        }
    }
    return ;
}

void insertafternode()
{
    temp=head;
    if(temp==NULL)
    {
        insertatend();
        return ;
    }
    int nodevalue,flag=0;
    printf("\nEnter the value of the node after which to enter the newnode : ");
    scanf("%d",&nodevalue);
    if(nodevalue==tail->data)
    {
        insertatend();
        return ;
    }
    while(temp->next!=head)
    {
        if(temp->data==nodevalue)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nThe entered node value was not found in the List");
        printf("\nPress any key to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    printf("\nElement inserted successfully!");
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
void insertatend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
void insertatfirst()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        tail->next=head;
    }
    printf("\nPress any key to continue : ");
    scanf(" %c",&ch);
    return ;
}
