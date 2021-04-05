#include"LStack.h"
int main() {

    LinkStack s;
	ElemType e = (ElemType)malloc(sizeof(ElemType));
	ElemType l = (ElemType)malloc(sizeof(ElemType));
	printf(
		"*请输入对应编号（请先初始化）*\n"
		"|1.初始化链式栈\n"
		"|2.给栈赋值\n"
		"|3.判断是否为空栈\n"
		"|4.得到栈顶元素\n"
		"|5.清空栈\n"
		"|6.销毁栈\n"
		"|7.检测栈长度\n"
		"|8.退出系统\n"
	);
	char c = '0';
	while (c != 8)
	{
		printf("你的选择是：");
		while (scanf_s("%d", &c) == 0)
		{
			printf("输入了非法字符，请重新输入：");
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
		default: printf("输入有误！请重新输入！"); break;
		}
	}
}