#include"LStack.h"
int main() {

    LinkStack s;
	ElemType e = (ElemType)malloc(sizeof(ElemType));
	ElemType l = (ElemType)malloc(sizeof(ElemType));
	printf(
		"*�������Ӧ��ţ����ȳ�ʼ����*\n"
		"|1.��ʼ����ʽջ\n"
		"|2.��ջ��ֵ\n"
		"|3.�ж��Ƿ�Ϊ��ջ\n"
		"|4.�õ�ջ��Ԫ��\n"
		"|5.���ջ\n"
		"|6.����ջ\n"
		"|7.���ջ����\n"
		"|8.�˳�ϵͳ\n"
	);
	char c = '0';
	while (c != 8)
	{
		printf("���ѡ���ǣ�");
		while (scanf_s("%d", &c) == 0)
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch (c)
		{
		case 1:initLStack(&s); break;
		case 2:push(&s); break;
		case 3:isEmptyLStack(&s); break;
		case 4:getTopLStack(&s, &e); break;
		case 5:clearLStack(&s); break;
		case 6:destroyLStack(&s); break;
		case 7:LStackLength(&s, &l); break;
		case 8:printf("Thank you!"); break;
		default: printf("�����������������룡"); break;
		}
	}
}