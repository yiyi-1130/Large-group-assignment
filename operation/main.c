#include<stdio.h>
#include"operations.h"
int main() 
{
	Stack num, ope;//numΪ�����ֵ��ջ��opeΪ����������ջ
	char str[100] = {0};
	int i =0;
	int a = 0, b;
	initStack(&num);
	initStack(&ope);
	//����һ���ַ���
	printf("Please enter the operation formula:");
	scanf_s("%s", str, sizeof(str));
	//�˳�ѭ��������Ϊstr[i]='\0'���ҷ���ջΪ��
	while (str[i] != '\0' || isEmptyStack(&ope) != 1)
	{
		//��Ϊ��ȷ��һ����ֵ��λ����ʹ��ѭ���жϣ��ñ���a�����
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
			//���Ž�ջ������������1.����ջΪ�� 2.����ջ��ջ��Ϊ'(' 3.����Ԫ�����ȼ�����ջ��Ԫ��
			if ((isEmptyStack(&ope) == 1) || (Priority(str[i]) > Priority(getTopLStack(&ope))) || ((getTopLStack(&ope) == '(') && str[i] != ')'))
			{
				pushStack(&ope, str[i]); i++; continue;
			}
			//��ջ����������������ջջ��Ϊ'(', ͬʱ����Ԫ��Ϊ')',���ջ
			if ((getTopLStack(&ope) == '(') && (str[i] == ')'))
			{
				popStack(&ope); i++; continue;
			}
			//����������1.����Ԫ�������� 2.����Ԫ�ط������ȼ������ڷ���ջջ�� 3.����Ԫ�ط���Ϊ')'��ջ����Ϊ'('��
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