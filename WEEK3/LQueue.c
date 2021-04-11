#include"LQueue.h"
void InitLQueue(LQueue* Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if(!Q->front)
		return FALSE; 
	Q->rear->next = NULL; 
	Q->length = 0;
	printf("初始化成功！\n");
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
Status Enl(LQueue* Q)//给队列赋值
{
	printf("请输入你想赋值的数据(按9999退出赋值）：\n");
	int data;
	scanf_s("%d", &data);
	while (data != 9999)
	{
		EnLQueue(Q,&data);
		scanf_s("%d", &data);
	}
	printf("赋值成功!\n");
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
	printf("销毁成功！\n");
	return TRUE;
}
Status GetHeadLQueue(LQueue* Q, void* e)
{
	Node* p = (void*)malloc(sizeof(int));
	p = Q->front->next;
	printf("队头元素为：");
	LPrint(p->data);
	printf("\n");
}
int LengthLQueue(LQueue* Q) 
{
	printf("队列的长度为%d.\n", Q->length);
	return Q->length;
}
Status DeLQueue(LQueue* Q) 
{
	if (IsEmptyLQueue(Q)) {
		printf("队列为空，不能出队列!\n");
		return FALSE;

	}
		    //把当前链队列的头的数据赋值给x
		   LQueue* Node = Q->front;
	
		 //移动指针 如果有的话 front指向下一个结点
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
	printf("队列中的元素为：");
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
		"*请输入对应编号（请先初始化）*\n"
		"|1.初始化队列\n"
		"|2.给队列赋值\n"
		"|3.判断队列是否为空\n"
		"|4.查看队头元素\n"
		"|5.清空栈\n"
		"|6.销毁栈\n"
		"|7.检测队列长度\n"
		"|8.遍历队列\n"
		"|9.退出系统\n"
	);
}