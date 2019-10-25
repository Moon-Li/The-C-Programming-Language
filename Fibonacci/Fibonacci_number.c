/*
求第n位斐波那契数
*/
#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)

int Fibonacci(int n)  //递归函数
{
	if (n < 3)
		return 1;
	else 
		 return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int n = 0;
	int num = 0;
	printf("请输入需要输出第多少位斐波那契数：");
	scanf("%d", &n);
	num = Fibonacci(n);
	printf("%d", num);
	system("pause");
	return 0;
}