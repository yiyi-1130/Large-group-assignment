#include"AQueue.h"
#include<stdlib.h>
#include<stdio.h>
int main()
{
	AQueue* Q = (AQueue*)malloc(sizeof(AQueue));
	void* e= NULL;
	menu();
	char c = '0';
	while (c != 10)
	{
		printf("���ѡ���ǣ�");
		while (scanf_s("%hhd", &c) == 0)
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (c)
		{
		case 1: InitAQueue(Q); break;
		case 2: Enl(Q); break;
		case 3:IsFullAQueue(Q); break;
		case 4:IsEmptyAQueue(Q); break;
		case 5:GetHeadAQueue(Q,e); break;
		case 6:DestoryAQueue(Q); break;
		case 7:ClearAQueue(Q); break;
		case 8:LengthAQueue(Q); break;
		case 9:TraverseAQueue(Q, APrint); break;
		case 10:printf("Thank you!"); break;
		default: printf("�����������������룡"); break;
		}
		system("pause");
		system("cls");
		menu();
	}
}