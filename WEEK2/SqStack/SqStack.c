#include<stdio.h>
#include<malloc.h>
#include"SqStack.h"
Status initStack(SqStack* s, int sizes)//初始化栈,初始化后为空栈。
{
	    s->elem = info;
		s->top = -1;//空栈
		s->size = sizes;
		printf("初始化完成!\n");
		return SUCCESS;
}
Status pushStack(SqStack* s, ElemType data)//入栈
{
	if (s->top ==s->size-1) {
		return ERROR;
	}
	s->top++;
	s->elem = data;
	return SUCCESS;
}
Status push(SqStack* s)//栈赋值
{
	if (s != NULL) {
		if (s->top == s->size - 1) {
			printf("栈已满，无法再插入数据！\n");
			return ERROR;
		}
	}
	ElemType x;
	printf("请输入你想插入的数据：\n");
	scanf_s("%d", &x);
	while (s->top != s->size - 1)
	{
		pushStack(s, x);
		scanf_s("%d", &x);
	}
	printf("栈已满，前%d个数已成功插入栈，后面无法再插入数据！\n",s->size);
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//判断栈是否为空
{
	if (s->top == -1)
	{
		printf("The stack is empty.\n");
		return SUCCESS;
	}
	else {
		printf("The stack isn't empty.\n");
		return ERROR;
	}
}
Status getTopStack(SqStack* s, ElemType* e) //得到栈顶元素
{
	if (s->top == -1) {
		printf("The stack is empty.\n");
		return ERROR;
	}
	else
	{
		e = s->elem;
		printf("The top stack element is %d \n",e);
		return SUCCESS;
	}
}
Status clearStack(SqStack* s)//清空栈
{
	if (s->top == -1) {
		printf("The stack is empty.\n");
		return SUCCESS;
	}
	else {
		s->top = -1;
		printf("The stack is cleared.\n");
		return SUCCESS;
	}
}
Status destroyStack(SqStack* s)//销毁栈
{
	s->size = 0;
	s->top = -1;
	s->elem=0;
	return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//检测栈长度
{
	if (s->top == -1)
	{
		printf("The stack is empty.\n");
		return ERROR;
	}
	else {
		length = s->top + 1;
		printf("The  length of stack is %d.\n ",length);
		return SUCCESS;
	}
}
Status popStack(SqStack* s, ElemType* data)//出栈
{
	if (s->top == -1)
		return ERROR;
	data = s->elem;
	s->top--;
	return SUCCESS;
}
