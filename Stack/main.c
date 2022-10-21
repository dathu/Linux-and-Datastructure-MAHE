/**********************************************************************************************************
TITLE: Check for balanced parentheses in an expression.
**********************************************************************************************************/
//extension of matching of nested parentheses
//( ) parentheses
//[ ] brackets
//{} braces



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

struct stack
{
	int capacity;
	int top;
	char *arr;
};

struct stack *create_stack(int cap)
{
	struct stack *s;
	s=malloc(sizeof(struct stack));
	s->capacity=cap;
	s->top=-1;
	s->arr=(char *)malloc(sizeof(char)* cap);
	return s;
}

void push(struct stack *s, char data)
{
	if(s->top==-1)
	{
		s->top=0;
		s->arr[s->top]=data;
	}
	else if(s->top== s->capacity-1)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top+=1;
		s->arr[s->top]=data;
	}
}

char pop(struct stack *s)
{
	char data;
	if(s->top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		data=s->arr[s->top];
		s->top-=1;
	}
	return data;
}

int match(char a, char b)
{
	if(a=='(' && b==')')
	{
		return 1;
	}
	if(a=='[' && b==']')
	{
		return 1;
	}
	if(a=='{' && b=='}')
	{
		return 1;
	}
	return 0;
}

int multi_parenthis(struct stack *s, char *exp)
{
	char popch;
	for(int i=0; exp[i]!='\0'; i++)
	{
		if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
		{
			push(s,exp[i]);
		}
		else if(exp[i]=='}' || exp[i]==')' || exp[i]==']')
		{
			if(s->top==-1)
			{
				return 0;
			}
			popch=pop(s);
			if(!match(popch, exp[i]))
			{
				return 0;
			}
		}
	}

	if(s->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
	struct stack *s1;
	s1=create_stack(10);
	char exp[SIZE];

	//char *exp="{7-(3-2)+[8+(99-5)]}";

	printf("\nEnter an expression:\n");
	gets(exp); //Taking the expression to be checked from user

	if(multi_parenthis(s1,exp)!=1)
		printf("Parenthesis are Not Balanced\n");
	else
		printf("Parenthesis are Balanced\n");
	return 0;
}
