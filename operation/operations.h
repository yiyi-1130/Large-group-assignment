#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef enum Status//����ö��ֵ
{
	ERROR = 0,
	SUCCESS = 1
} Status;
//����һ���ṹ��ڵ�
typedef  struct node
{
	int data;
	struct Node* next;
}Node;
//����һ��ջ
typedef  struct stack
{
	Node* top;
	int	count;
}Stack;
Status initStack(Stack* s);//��ʼ��ջ
int isEmptyStack(Stack* s);//�жϿ�ջ
int pushStack(Stack* s, int e);//��ջ
int popStack(Stack* s);//��ջ
int getTopLStack(Stack* s);//��ȡջ��Ԫ��
int Priority(char c);//���ȼ�����