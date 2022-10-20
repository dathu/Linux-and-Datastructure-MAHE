#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	int capacity;
	int top;
	char *arr;
};

struct stack *create_stack(int cap)
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->capacity=cap;
	s->top=-1;
	s->arr=(char *)malloc(sizeof(char) *cap);

	return s;
}

void push(struct stack *s, char data)
{
	if(s->top==-1)
	{
		s->top=0;
		s->arr[s->top]=data;
	}
	else if(s->top==s->capacity-1)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top+=1;
		s->arr[s->top]=data;
	}
}

void pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		s->top-=1;
	}
}

int parenthis_match(struct stack *s, char *exp)
{
	for(int i=0; exp[i]!='\0'; i++)
	{
		if(exp[i]== '(')
		{
			push(s, exp[i]);
			//push(s, '(');
		}
		else if(exp[i]== ')')
		{
			if(s->top==-1)
			{
				return 0;
			}
			pop(s);
		}
	}
	
	if(s->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int count(struct stack *s)
{
	return s->top+1;
}

int main()
{
	struct stack *s1;
	s1=create_stack(10);

	char *exp="(1*(8-3(7)";

	if((parenthis_match(s1,exp)!=1))
		printf("Parenthis is not matching\n");
	else
		printf("Parenthis is matching\n");

	printf("Top ( present: %d\n",count(s1));
	return 0;
}
