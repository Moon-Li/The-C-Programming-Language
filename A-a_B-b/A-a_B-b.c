/*
��ĸת����Сд
*/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int main()
{
	char i;
	while (1)
	{
		fflush(stdin); //Ϊ�˱�������ϴ�����Ļس���������������������ַ�����������#include <stdlib.h>ͷ�ļ�
		printf("�����룺");
		scanf("%c", &i);
		if (i > 64 && i < 91)
		{
			i = i + 32;
			printf("�����%c\n", i);
		}
		else if (i>96 && i < 123)
		{
			i = i - 32;
			printf("�����%c\n", i);
		}
		else
		{
			printf("��������\n");
		}
	}
	system("pause");
	return 0;
}