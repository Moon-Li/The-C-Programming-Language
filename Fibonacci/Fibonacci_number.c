/*
���nλ쳲�������
*/
#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)

int Fibonacci(int n)  //�ݹ麯��
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
	printf("��������Ҫ����ڶ���λ쳲���������");
	scanf("%d", &n);
	num = Fibonacci(n);
	printf("%d", num);
	system("pause");
	return 0;
}