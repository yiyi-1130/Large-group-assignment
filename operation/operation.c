#include<stdio.h>
#include"operations.h"
Status initStack(Stack* s)
{
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}
int isEmptyStack(Stack* s)
{
	if (s->count == 0) return SUCCESS;
	else return ERROR;
}
int pushStack(Stack* s, int e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p != NULL)
	{
		p->data = e;
		p->next = s->top;
		s->top = p;
		s->count++;
		return SUCCESS;
	}
	else return ERROR;
}
int popStack(Stack* s)
{
	int e;

	if (s->top==NULL)
		return ERROR;
	else
	{
		Node* p = s->top;
		e = p->data;
		s->top = p->next;
		free(p);
		s->count--;
		return e;
	}
}
int getTopLStack(Stack* s)
{
	if (s->top == NULL)
		return ERROR;
	 return (s->top->data);
}
int Priority(char c)
{
	if (c == '(')
		return 3;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else return 0;
}
