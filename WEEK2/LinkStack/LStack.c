#include"LStack.h"
#include<stdio.h>
Status initLStack(LinkStack* s)//��ʼ��ջ
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	printf("��ʼ�����!\n");
	return SUCCESS;
}
Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->count == 0)
	{
		printf("The LinkStack is empty.\n");
		return SUCCESS;
	}
	else
	{
		printf("The LinkStack isn't empty.\n");
		return ERROR;
	}
}
Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	if (s->top == NULL)
	{
		p->next = NULL;
		p->data = data;
		s->top = p;
	}
	else
	{
		p->next = s->top;
		p->data = data;
		s->top = p;
	}
	s->count++;
	return SUCCESS;
}
Status push(LinkStack* s)//��ջ��ֵ
{
	ElemType x;
	printf("������������������(��9999�˳���ֵ����\n");
	scanf_s("%d", &x);
	while (x != 9999)
	{
		pushLStack(s, x);
		scanf_s("%d", &x);
	}
	printf("����ɹ�!\n");
	return SUCCESS;
}
Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	ElemType a;
	if (s->top == NULL)
		return ERROR;
	else
		*e = s->top->data;
		a = s->top->data;
	printf("The element of topstack is %d", a);
	return SUCCESS;
}
Status clearLStack(LinkStack* s)//���ջ
{
	if (!s)
		return ERROR;
	else
	{
		LinkStackPtr p1, p2;
		p1 = p2 = s->top;
		while (p2 != NULL)
		{
			p2 = p2->next;
			free(p1);
			p1 = p2;
		}
		s->top = NULL;
		s->count = 0;
		return SUCCESS;
	}
}
Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	int L;
	*length = s->count;
	L = s->count;
	printf("The length of stack is %d.\n",L);
	return SUCCESS;
}
Status destroyLStack(LinkStack* s)//����ջ
{
	if (!s)
		return ERROR;
	else
	{
		clearLStack(s);
		s->top = NULL;
		s->count = -1;
		return SUCCESS;
	}
}
