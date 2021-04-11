#include"LQueue.h"
#include<stdlib.h>
#include<stdio.h>
int main()
{
	LQueue *Q = (LQueue*)malloc(sizeof(LQueue));
	void* e=NULL;
	menu();
	char c = '0';
	while (c != 8)
	{
		printf("你的选择是：");
		while (scanf_s("%hhd", &c) == 0)
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch (c)
		{
		case 1:InitLQueue(Q);break;
		case 2:Enl(Q);break;
		case 3:IsEmptyLQueue(Q);
			if (IsEmptyLQueue(Q) == 0)
				printf("队列不为空\n");
			else printf("队列为空\n"); 
			break;
		case 4:GetHeadLQueue(Q,e);break;
		case 5:ClearLQueue(Q); printf("队列已清空！\n"); break;
		case 6:DestoryLQueue(Q); break;
		case 7:LengthLQueue(Q); break;
		case 8:TraverseLQueue(Q, LPrint); break;
		case 9:printf("Thank you!"); break;
		default: printf("输入有误！请重新输入！"); break;
		}system("pause");
	 system("cls");
	 menu();

	}
}