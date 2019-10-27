/*
字母转化大小写
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
		fflush(stdin); //为了避免读入上次输入的回车，清空输入流缓冲区的字符，必须引入#include <stdlib.h>头文件
		printf("请输入：");
		scanf("%c", &i);
		if (i > 64 && i < 91)
		{
			i = i + 32;
			printf("输出：%c\n", i);
		}
		else if (i>96 && i < 123)
		{
			i = i - 32;
			printf("输出：%c\n", i);
		}
		else
		{
			printf("输入有误！\n");
		}
	}
	system("pause");
	return 0;
}