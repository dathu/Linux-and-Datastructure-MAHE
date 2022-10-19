#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*tail,*temp,*new_node;

char ch;

void insert();
void insert_at_front();
void insert_at_end();
void insert_after_node();
void display();
void delete();
void del_from_front();
void del_from_end();
void del_after_node();
void displayq(int);
void search();
void count();
void reverse();


int main()
{
    int choice=0;
    while(choice<12)
    {
        system("cls");
        printf("\n--SINGLY LINKED LIST OPERATIONS--\n");
        printf("\n 1-> Insert node/s");
        printf("\n 2-> Delete node");
        printf("\n 3-> Display");
        printf("\n 4-> Search a node");
        printf("\n 5-> Count the no.of nodes");
        printf("\n 6-> Reverse the Linked List");
        //printf("\n 7-> Middle Element");
        //printf("\n 8-> Sort the Linked List");
        //printf("\n 9-> Remove Duplicates from Sorted List");
        //printf("\n 10-> Check if List is palindrome");
        //printf("\n 11-> Remove Nth node from end");
        printf("\n 12-> Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)  //switch case statements.
        {
            case 1: insert();break;
            case 2: delete();break;
            case 3: display();break;
            case 4: search(); break;
            case 5: count(); break;
            case 6: reverse(); break;
            //case 7: middle(); break;
            //case 8: sort(); break;
            //case 9: rem_dup(); break;
            //case 10: palin(); break;
            //case 11: remnth(); break;
            default: printf("\nProgram ended\n\nThankyou MSIS, MAHE, MAIPAL!"); //program ends
        }
    }
    return 0;
}

void reverse()
{
    if(head==NULL)
    {
        printf("\nThe List is empty!\n");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    struct node *prev_node,*curr_node,*next_node;
    prev_node=NULL;
    curr_node=next_node=head;
    while(next_node!=NULL)
    {
        next_node=next_node->next;
        curr_node->next=prev_node;
        prev_node=curr_node;
        curr_node=next_node;
    }
    temp=head;
    head=tail;
    tail=temp;
    printf("\nThe Linked List is successfully reversed!\n");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}

void count()
{
    int num=0;
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    while(temp!=NULL)
    {
        num++;
        temp=temp->next;
    }
    printf("\nThe total no.of nodes in the List is : %d",num);
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return;
}

void search()
{
    int ele;
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nEnter the value of the node to search : ");
    scanf("%d",&ele);
    while(temp!=NULL)
    {
        if(ele==temp->data)
        {
            printf("\n--Element found!--\n");
            displayq(ele);
            printf("\nPress 'y' to continue : ");
            scanf(" %c",&ch);
            return ;
        }
        temp=temp->next;
    }
    printf("\n--Element not found!--");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
    return ;
}

void displayq(ele)
{
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==ele && temp==tail)
        {
            printf(" *(%d)* -> NULL",temp->data);
        }
        else if(temp->data==ele)
        {
            printf(" *(%d)* -> ",temp->data);
        }
        else if(temp==tail)
        {
            printf(" %d -> NULL",temp->data);
        }
        else
        {
            printf(" %d ->",temp->data);
        }
        temp=temp->next;
    }
}

void delete()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--DELETION OF NODE--\n");
        printf("\n 1-> Delete from the beginning");
        printf("\n 2-> Delete from the end");
        printf("\n 3-> Delete specific node");
        printf("\n 4-> Exit");
        printf("\nhead=%d and tail=%d",head,tail);
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: del_from_front();break;
            case 2: del_from_end();break;
            case 3: del_after_node(); break;
            default: break;
        }
    }
}

void del_after_node()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    int value;
    printf("\nEnter the value of node to delete : ");
    scanf("%d",&value);
    if(head==tail)
    {
        if(value!=temp->data)
        {
            printf("\nElement not present in the List");
            printf("\nPress 'y' to continue : ");
            scanf(" %c",&ch);
            return ;
        }
        else
        {
            printf("\nElement deleted is : %d",temp->data);
            head=NULL; tail=NULL;
            free(temp);
            printf("\nPress 'y' to continue : ");
            scanf(" %c",&ch);
            return ;
        }
    }
    if(value==temp->data)
    {
        del_from_front();
        return ;
    }
    while(temp->next->data!=value)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("\nThe element is not present in the List");
            printf("\nPress 'y' to continue : ");
            scanf(" %c",&ch);
            return ;
        }
    }
    if(temp->next->next==NULL)
    {
        del_from_end();
        return ;
    }
    struct node* y;
    y=temp->next;
    temp->next=temp->next->next;
    printf("\nThe element deleted is : %d",y->data);
    y->next=NULL;
    free(y);
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);

}
void del_from_end()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    if(head==tail)
    {
        printf("\nThe element deleted is : %d",temp->data);
        free(temp);
        head=NULL;
        tail=NULL;
        printf("\nElement deleted successfully!\n");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    printf("\nThe element deleted is %d",tail->data);
    free(tail);
    tail=temp;
    tail->next=NULL;
    printf("\nElement deleted successfully!\n");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}
void del_from_front()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    if(head==tail)
    {
        printf("\nThe element deleted is : %d",temp->data);
        free(temp);
        head=NULL;
        tail=NULL;
        printf("\nElement deleted successfully!\n");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    head=head->next;
    printf("\nThe element deleted is : %d",temp->data);
    temp->next=NULL;
    free(temp);
    printf("\nElement deleted successfully!\n");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}

void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is empty");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    printf("\nThe Linked List is : \n");
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            printf(" %d ->",temp->data);
        }
        else
        {
            printf(" %d -> NULL.",temp->data);
        }
        temp=temp->next;
    }
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}

void insert()
{
    int choice=0;
    while(choice<4)
    {
        system("cls");
        printf("\n--INSERTION OF NODE--\n");
        printf("\n 1-> Insert at Beginning/Front");
        printf("\n 2-> Insert at End");
        printf("\n 3-> Insert after Node");
        printf("\n 4-> Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_at_front();break;
            case 2: insert_at_end(); break;
            case 3: insert_after_node(); break;
            default: break;
        }
    }
}

void insert_at_front()
{
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
        tail=new_node;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
    printf("\nElement inserted successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}
void insert_at_end()
{
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(tail==NULL)
    {
        head=new_node;
        tail=new_node;
    }
    else
    {
        tail->next=new_node;
        tail=new_node;
    }
    printf("\nElement inserted successfully!");
    printf("\nPress 'y' to continue : ");
    scanf(" %c",&ch);
}
void insert_after_node()
{
    int value;
    if(head==NULL)
    {
        printf("\n--List is empty--");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
        return ;
    }
    else
    {
        printf("\nInsert the node after which you want to insert the node : ");
        scanf("%d",&value);
        temp=head;
        while(temp->data!=value)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\nElement is not present");
                printf("\nPress 'y' to continue : ");
                scanf(" %c",&ch);
                return ;
            }
        }
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nInsert the data : ");
        scanf("%d",&new_node->data);
        new_node->next=temp->next;
        temp->next=new_node;
        printf("\nElement inserted successfully!");
        printf("\nPress 'y' to continue : ");
        scanf(" %c",&ch);
    }
}
