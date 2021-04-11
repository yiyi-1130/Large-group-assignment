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
	printf("��ʼ����ɣ�\n");
}
void DestoryAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
	printf("���дݻ���ɣ�\n");
}
Status IsFullAQueue(const AQueue* Q)
{
	if (Q->length == MAXQUEUE) //�������
	{
		printf("����������\n");
		return TRUE;
	}
	printf("����δ����\n");
	return FALSE;
}
Status IsEmptyAQueue(const AQueue* Q) 
{
	if (Q->front == Q->rear)
	{
		printf("����Ϊ�գ�\n");
		return TRUE;
	}
	else
		printf("���в�Ϊ�գ�\n");
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
		printf("��ͷԪ��Ϊ��");
		APrint(Q->data[i]);
		printf("\n");
		return TRUE;
	}
}
int LengthAQueue(AQueue* Q)
{
	printf("���еĳ���Ϊ%d.\n", Q->length);
	return Q->length;
}
Status EnAQueue(AQueue* Q, void* data)
{
	if (Q->length == MAXQUEUE) //�������
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
	printf("��������գ�\n");
}
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) 
{
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	printf("�����е�Ԫ��Ϊ��");
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
Status Enl(AQueue* Q)//�����и�ֵ
{
	printf("���������븳ֵ������(��9999�˳���ֵ����\n");
	int d;
	scanf_s("%d", &d);
	while (d != 9999)
	{
		EnAQueue(Q, &d);
		scanf_s("%d", &d);
	}
	printf("��ֵ�ɹ�!\n");
	return TRUE;
}
void menu() 
{
	printf(
		"*�������Ӧ��ţ����ȳ�ʼ����*\n"
		"|1.��ʼ������\n"
		"|2.�����и�ֵ\n"
		"|3.�ж϶����Ƿ�����\n"
		"|4.�ж϶����Ƿ�Ϊ��\n"
		"|5.�鿴��ͷԪ��\n"
		"|6.����ջ\n"
		"|7.���ջ\n"
		"|8.�����г���\n"
		"|9.��������\n"
		"|10.�˳�ϵͳ\n"
	);
}