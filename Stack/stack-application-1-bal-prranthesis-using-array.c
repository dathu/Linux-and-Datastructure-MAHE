/**********************************************************************************************************
TITLE: Check for balanced parentheses in an expression.
**********************************************************************************************************/
//extension of matching of nested parentheses
//( ) parentheses
//[ ] brackets
//{} braces
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

typedef struct
{
	char a[SIZE];
	int tos;
}Stack;

void push (Stack *p,double x)
{
	p->tos++;
	p->a[p->tos]=x;
}

//Pop Function
char pop(Stack *p)
{
	return(p->a[p->tos--]);
}
int main()
{
	Stack s1;
	char exp[SIZE];
	int i;
	s1.tos=-1; //Initializing the top of stack to -1
	printf("\nEnter an expression:\n");
	gets(exp); //Taking the expression to be checked from user
	char bracket;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[') //Condition for opening bracket
		{
			push(&s1,exp[i]); //Pushing the opening bracket
		}
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']') //condition for closing brackets
		{
			if(s1.tos != -1)
			{
				bracket = pop(&s1);
				switch(exp[i])
				{
					case ')':
						if( bracket == '{' || bracket == '[' )
						{
							printf("\nCorresponding '(' missing");
							exit(0);
						}
						break;

					case ']':

						if( bracket == '{' || bracket == '(' )
						{
							printf("\nCorresponding '[' missing");
							exit(0);
						}
						break;

					case '}':

					if( bracket == '(' || bracket == '[' )

					{

						printf("\nCorresponding '{' missing");

						exit(0);

					}
				}
			}
		else
		{ //if stack is empty

			printf("\nCorresponding '(' or '{' or '[' missing"); // does not have a corresponding opening bracket/parentheses/braces
			exit(0); // exit from program execution with return status as 0
		}
	}
}
/*After traversing entire string*/

if(s1.tos != -1) //check if stack is not empty
	printf("\nCorresponding ')' or '}' or ']' missing");
else //if stack is empty
	printf("\nMatched"); //equal no of brackets
	return 0;
}
