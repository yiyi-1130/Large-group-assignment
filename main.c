#include"SqStack.h"
#include<stdio.h>
int main()
{
	SqStack* s;
	SqStack* base;
	base = (SqStack*)malloc(sizeof(SqStack));
	s = (SqStack*)malloc(sizeof(SqStack));
	char c = '0';
	ElemType sizes;
	ElemType* e;
	e= (ElemType*)malloc(sizeof(ElemType));
	ElemType* L;
	L = (ElemType*)malloc(sizeof(ElemType));
	ElemType* data;
	data = (ElemType*)malloc(sizeof(ElemType));
	printf(
		"*�������Ӧ��ţ����ȳ�ʼ����*\n"
		"|1.��ʼ��ջ\n"
		"|2.��ջ��ֵ\n"
		"|3.�ж��Ƿ�Ϊ��ջ\n"
		"|4.�õ�ջ��Ԫ��|n"
		"|5.���ջ\n"
		"|6.����ջ\n"
		"|7.���ջ����\n"
		"|8.��ջ�����Ԫ��\n"
		"|9.�˳�ϵͳ \n"
		);
	while (c != 9)
	{
		printf("���ѡ���ǣ�");
		while (scanf_s("%d", &c) == 0)
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (c)
		{
		case 1:
			printf("������ջ�Ĵ�С��");
			scanf_s("%d", &sizes);
			initStack(s, sizes);
			break;
		case 2:push(s); break;
		case 3:isEmptyStack(s);break;
		case 4:getTopStack(s,e); break;
		case 5:	clearStack(s); break;
		case 6:destroyStack(s); break;
        case 7:stackLength(s,L); break;
		case 8:popStack(s,data); break;
		default: printf("�����������������룡"); break;
		}
	}
	return 0;
}