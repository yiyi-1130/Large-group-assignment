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
		printf("���ѡ���ǣ�");
		while (scanf_s("%hhd", &c) == 0)
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (c)
		{
		case 1:InitLQueue(Q);break;
		case 2:Enl(Q);break;
		case 3:IsEmptyLQueue(Q);
			if (IsEmptyLQueue(Q) == 0)
				printf("���в�Ϊ��\n");
			else printf("����Ϊ��\n"); 
			break;
		case 4:GetHeadLQueue(Q,e);break;
		case 5:ClearLQueue(Q); printf("��������գ�\n"); break;
		case 6:DestoryLQueue(Q); break;
		case 7:LengthLQueue(Q); break;
		case 8:TraverseLQueue(Q, LPrint); break;
		case 9:printf("Thank you!"); break;
		default: printf("�����������������룡"); break;
		}system("pause");
	 system("cls");
	 menu();

	}
}