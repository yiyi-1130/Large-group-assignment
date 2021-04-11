#include"LQueue.h"
void InitLQueue(LQueue* Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if(!Q->front)
		return FALSE; 
	Q->rear->next = NULL; 
	Q->length = 0;
	printf("��ʼ���ɹ���\n");
	return TRUE;
	
}
Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void*)malloc(sizeof(int));
	memcpy(p->data, data,sizeof(int));
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;
}
Status Enl(LQueue* Q)//�����и�ֵ
{
	printf("���������븳ֵ������(��9999�˳���ֵ����\n");
	int data;
	scanf_s("%d", &data);
	while (data != 9999)
	{
		EnLQueue(Q,&data);
		scanf_s("%d", &data);
	}
	printf("��ֵ�ɹ�!\n");
	return TRUE;
}
Status IsEmptyLQueue(const LQueue* Q) 
{
	if (Q->front==Q->rear)
	{
		return TRUE;
	}
    return FALSE;
}
void DestoryLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	ClearLQueue(Q);
	Q->front = Q->rear= NULL;
	printf("���ٳɹ���\n");
	return TRUE;
}
Status GetHeadLQueue(LQueue* Q, void* e)
{
	Node* p = (void*)malloc(sizeof(int));
	p = Q->front->next;
	printf("��ͷԪ��Ϊ��");
	LPrint(p->data);
	printf("\n");
}
int LengthLQueue(LQueue* Q) 
{
	printf("���еĳ���Ϊ%d.\n", Q->length);
	return Q->length;
}
Status DeLQueue(LQueue* Q) 
{
	if (IsEmptyLQueue(Q)) {
		printf("����Ϊ�գ����ܳ�����!\n");
		return FALSE;

	}
		    //�ѵ�ǰ�����е�ͷ�����ݸ�ֵ��x
		   LQueue* Node = Q->front;
	
		 //�ƶ�ָ�� ����еĻ� frontָ����һ�����
		    if (Q->front == Q->rear) {
				Q->front = NULL;
		       Q->rear = NULL;
			   Q->length = 0;
			}
			else {
				Q->front = Q->front->next;
				(Q->length)--;
			}
	     free(Node);
	     return TRUE;
}
void ClearLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p, * q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return TRUE;
}
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))  
{
	if(Q->front!=NULL)
	{Node* p = (void*)malloc(sizeof(int));
	p = Q->front->next;
	printf("�����е�Ԫ��Ϊ��");
	while (p != NULL) {
		foo(p->data);
		printf(" ");
		p = p->next;
	}
	}
	printf("\n");
	return TRUE;
}
void LPrint(void* q) 
{
	printf("%d", *(int*)q);
}
void menu()
{
	printf(
		"*�������Ӧ��ţ����ȳ�ʼ����*\n"
		"|1.��ʼ������\n"
		"|2.�����и�ֵ\n"
		"|3.�ж϶����Ƿ�Ϊ��\n"
		"|4.�鿴��ͷԪ��\n"
		"|5.���ջ\n"
		"|6.����ջ\n"
		"|7.�����г���\n"
		"|8.��������\n"
		"|9.�˳�ϵͳ\n"
	);
}