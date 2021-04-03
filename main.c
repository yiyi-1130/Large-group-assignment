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
		"*请输入对应编号（请先初始化）*\n"
		"|1.初始化栈\n"
		"|2.给栈赋值\n"
		"|3.判断是否为空栈\n"
		"|4.得到栈顶元素|n"
		"|5.清空栈\n"
		"|6.销毁栈\n"
		"|7.检测栈长度\n"
		"|8.出栈并获得元素\n"
		"|9.退出系统 \n"
		);
	while (c != 9)
	{
		printf("你的选择是：");
		while (scanf_s("%d", &c) == 0)
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch (c)
		{
		case 1:
			printf("请输入栈的大小：");
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
		default: printf("输入有误！请重新输入！"); break;
		}
	}
	return 0;
}