#include<stdio.h>
#include"AQueue.h"
void InitAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void*)malloc(sizeof(int));
		Q->front = 0;
		Q->rear = 0;
		Q->length = 0;
	printf("初始化完成！\n");
}
void DestoryAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	printf("队列摧毁完成！\n");
}
Status IsFullAQueue(const AQueue* Q)
{
	if (Q->length == MAXQUEUE) //队满溢出
	{
		printf("队列已满！\n");
		return TRUE;
	}
	printf("队列未满！\n");
	return FALSE;
}
Status IsEmptyAQueue(const AQueue* Q) 
{
	if (Q->front == Q->rear)
	{
		printf("队列为空！\n");
		return TRUE;
	}
	else
		printf("队列不为空！\n");
	return FALSE;
}
Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (Q->length==0)
		return FALSE;
	else
	{
		
		int i = Q->front + 1;
		e = Q->data[i];
		printf("对头元素为：");
		APrint(Q->data[i]);
		printf("\n");
		return TRUE;
	}
}
int LengthAQueue(AQueue* Q)
{
	printf("队列的长度为%d.\n", Q->length);
	return Q->length;
}
Status EnAQueue(AQueue* Q, void* data)
{
	if (Q->length == MAXQUEUE) //队满溢出
		return FALSE;
	else
	{
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		memcpy(Q->data[Q->rear], data, sizeof(int));
		Q->length++;
		return TRUE;
	}
}

Status DeAQueue(AQueue* Q)
{
	if(Q->length == 0)
		return FALSE;
	else
	{
	Q->front = (Q->front + 1) % MAXQUEUE;
	Q->length--;
	return TRUE;
	}
}
void ClearAQueue(AQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
	printf("队列已清空！\n");
}
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) 
{
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	printf("队列中的元素为：");
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[i]);
		printf(" ");
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}
void APrint(void* q)
{
	printf("%d", *(int*)q);
}
Status Enl(AQueue* Q)//给队列赋值
{
	printf("请输入你想赋值的数据(按9999退出赋值）：\n");
	int d;
	scanf_s("%d", &d);
	while (d != 9999)
	{
		EnAQueue(Q, &d);
		scanf_s("%d", &d);
	}
	printf("赋值成功!\n");
	return TRUE;
}
void menu() 
{
	printf(
		"*请输入对应编号（请先初始化）*\n"
		"|1.初始化队列\n"
		"|2.给队列赋值\n"
		"|3.判断队列是否满了\n"
		"|4.判断队列是否为空\n"
		"|5.查看队头元素\n"
		"|6.销毁栈\n"
		"|7.清空栈\n"
		"|8.检测队列长度\n"
		"|9.遍历队列\n"
		"|10.退出系统\n"
	);
}