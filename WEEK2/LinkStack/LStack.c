#include"LStack.h"
#include<stdio.h>
Status initLStack(LinkStack* s)//初始化栈
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s->top)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	printf("初始化完成!\n");
	return SUCCESS;
}
Status isEmptyLStack(LinkStack* s)//判断栈是否为空
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
Status pushLStack(LinkStack* s, ElemType data)//入栈
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
Status push(LinkStack* s)//给栈赋值
{
	ElemType x;
	printf("请输入你想插入的数据(按9999退出赋值）：\n");
	scanf_s("%d", &x);
	while (x != 9999)
	{
		pushLStack(s, x);
		scanf_s("%d", &x);
	}
	printf("插入成功!\n");
	return SUCCESS;
}
Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
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
Status clearLStack(LinkStack* s)//清空栈
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
Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	int L;
	*length = s->count;
	L = s->count;
	printf("The length of stack is %d.\n",L);
	return SUCCESS;
}
Status destroyLStack(LinkStack* s)//销毁栈
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
