//$ Doubly Linked List

//header file
#include<stdio.h>
#include<malloc.h>

struct node 		//creating the Structure containing 3 items
{
	struct node *prev;		//point the previous memory(NODE)
	int data;
	struct node *next;

};


struct node *start=NULL;

// initalize the fuction having struct node type and return type (start)
struct node *create(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *display(struct node *);

int main()
{
	int option;
	do
	{
		printf("\nPress 1 for create: ");
		printf("\nPress 2 for insert_beg: ");
		printf("\nPress 3 for insert_end: ");
		printf("\nPress 4 for del_beg: ");
		printf("\nPress 5 for del_end: ");
		printf("\nPress 6 for display: ");
		printf("\nPress 7 for Exit:\n ");
		scanf("\n%d",&option);
		switch(option)
		{
			case 1: start=create(start);
			break;
			case 2: start =insert_beg(start);
			break;
			case 3: start=insert_end(start);
			break;
			case 4: start=del_beg(start);
			break;
			case 5: start=del_end(start);
			break;
			case 6: start=display(start);
			break;
		}
	}while(option!=7);
	return 0;
}

//create a Linked List
struct node * create(struct node * start)
{
	struct node *new_node,*ptr;		//maaking 2 struct node type variable
	int n;
	printf("\nPress -1 for Quit: ");
	printf("\nEnter The Number: ");
	scanf("\n%d",&n);
	while(n!=-1)
	{

		if(start==NULL)
		{
			new_node=(struct node *)malloc(sizeof(struct node));		//creating a node of struct node size
			new_node->prev=NULL;	//for creating the frst node the we have to assign prev NULL
			new_node->data=n;		//pushing item in the data portion of new_node
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->data=n;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->prev=ptr;
			new_node->next=NULL;
		}
		printf("\nEnter The Number: ");
		scanf("\n%d",&n);
	}

	return start;
}

//insert_beg
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int n;
	printf("\nEnter The Number to be inserted at BEG: ");
	scanf("\n%d",&n);
	new_node=(struct node *)malloc(sizeof(struct node ));
	new_node->data=n;
	start->prev=new_node;
	new_node->next=start;
	new_node->prev=NULL;
	start=new_node;
	//start=start->next;

	return start;
}

//insert_end
struct node *insert_end(struct node * start)
{
	struct node *new_node, *ptr;
	int n;
	printf("\nEnter The Number To be Inserted at END: ");
	scanf("\n%d",&n);
	new_node=(struct node *)malloc(sizeof(struct node ));
	new_node->data=n;
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	return start;
}

//delete At Beg
struct node *del_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	start=start->next;	//move the address of start node to second node
	start->prev=NULL;
	free(ptr);
	return start;
}

//delete At END
struct node * del_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=NULL)	//accessing the node
	{
			preptr=ptr;
			ptr=ptr->next;
	}
	preptr->next->prev=NULL;	//put NULL in the SECOND last node
	free(ptr);	//free the last node
	return start;
}


//display the Linked List

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);	//printing the elements on the data field in Linked List
		ptr=ptr->next;	//move to next node
	}
	return start;
}
