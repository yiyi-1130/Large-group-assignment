#include<stdio.h>
#include"operations.h"
int main() 
{
	Stack num, ope;//num为存放数值的栈，ope为存放运算符的栈
	char str[100] = {0};
	int i =0;
	int a = 0, b;
	initStack(&num);
	initStack(&ope);
	//输入一个字符串
	printf("Please enter the operation formula:");
	scanf_s("%s", str, sizeof(str));
	//退出循坏的条件为str[i]='\0'并且符号栈为空
	while (str[i] != '\0' || isEmptyStack(&ope) != 1)
	{
		//因为不确定一个数值的位数，使用循坏判断，用变量a来存放
		if (str[i] >= '0' && str[i] <= '9')
		{
			a = a * 10 + str[i]-'0';
			i++;
			if (str[i] < '0' || str[i]>'9')
			{
				pushStack(&num, a);
				a = 0;
			}
		}
		else
		{
			//符号进栈无运算条件：1.符号栈为空 2.符号栈的栈顶为'(' 3.数组元素优先级大于栈定元素
			if ((isEmptyStack(&ope) == 1) || (Priority(str[i]) > Priority(getTopLStack(&ope))) || ((getTopLStack(&ope) == '(') && str[i] != ')'))
			{
				pushStack(&ope, str[i]); i++; continue;
			}
			//出栈无运算条件：符号栈栈顶为'(', 同时数组元素为')',则出栈
			if ((getTopLStack(&ope) == '(') && (str[i] == ')'))
			{
				popStack(&ope); i++; continue;
			}
			//运算条件：1.数组元素已用完 2.数组元素符号优先级不大于符号栈栈顶 3.数组元素符号为')'且栈顶不为'('。
			if ((Priority(str[i]) <= Priority(getTopLStack(&ope))) || ((getTopLStack(&ope) != '(') && (str[i] == ')')) || (str[i] == '\0'))
			{
				switch (popStack(&ope))
				{
				case '+':
					pushStack(&num, popStack(&num) + popStack(&num));
					break;
				case '-':
					b = popStack(&num);
					pushStack(&num, popStack(&num) - b);
					break;
				case '*':
					pushStack(&num, popStack(&num) * popStack(&num));
					break;
				case '/':
					b = popStack(&num);
					pushStack(&num, popStack(&num) / b);
					break;
				}
				continue;
				
			}


		}

	}
    printf("result is:%d\n", getTopLStack(&num));
}