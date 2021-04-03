#include<stdio.h>
#include<malloc.h>
#include"SqStack.h"
Status initStack(SqStack* s, int sizes)//��ʼ��ջ,��ʼ����Ϊ��ջ��
{
	    s->elem = info;
		s->top = -1;//��ջ
		s->size = sizes;
		printf("��ʼ�����!\n");
		return SUCCESS;
}
Status pushStack(SqStack* s, ElemType data)//��ջ
{
	if (s->top ==s->size-1) {
		return ERROR;
	}
	s->top++;
	s->elem = data;
	return SUCCESS;
}
Status push(SqStack* s)//ջ��ֵ
{
	if (s != NULL) {
		if (s->top == s->size - 1) {
			printf("ջ�������޷��ٲ������ݣ�\n");
			return ERROR;
		}
	}
	ElemType x;
	printf("�����������������ݣ�\n");
	scanf_s("%d", &x);
	while (s->top != s->size - 1)
	{
		pushStack(s, x);
		scanf_s("%d", &x);
	}
	printf("ջ������ǰ%d�����ѳɹ�����ջ�������޷��ٲ������ݣ�\n",s->size);
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//�ж�ջ�Ƿ�Ϊ��
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
Status getTopStack(SqStack* s, ElemType* e) //�õ�ջ��Ԫ��
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
Status clearStack(SqStack* s)//���ջ
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
Status destroyStack(SqStack* s)//����ջ
{
	s->size = 0;
	s->top = -1;
	s->elem=0;
	return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//���ջ����
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
Status popStack(SqStack* s, ElemType* data)//��ջ
{
	if (s->top == -1)
		return ERROR;
	data = s->elem;
	s->top--;
	return SUCCESS;
}
