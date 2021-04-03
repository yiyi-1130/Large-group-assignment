#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef enum Status//定义枚举值
{
	ERROR = 0,
	SUCCESS = 1
} Status;
//定义一个结构体节点
typedef  struct node
{
	int data;
	struct Node* next;
}Node;
//定义一个栈
typedef  struct stack
{
	Node* top;
	int	count;
}Stack;
Status initStack(Stack* s);//初始化栈
int isEmptyStack(Stack* s);//判断空栈
int pushStack(Stack* s, int e);//入栈
int popStack(Stack* s);//出栈
int getTopLStack(Stack* s);//获取栈底元素
int Priority(char c);//优先级定义