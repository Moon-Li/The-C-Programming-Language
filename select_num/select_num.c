/*
在有序数组中查询数字
*/

#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

int selectqq(int x,int a[],int y);

int main()
{
	int arr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	int num = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("请输入所要查询的数字：\n");
	scanf("%d", &num);
	int ret = selectqq(num,arr,sz);
	printf("地址是：%d\n", ret);
	system("pause");
	return 0;
}

int selectqq(int x,int a[],int y)
{
	int left = 0;
	int count = 0;
	int middle = 0;
	int right = y - 1;
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		count++;
		if (x > a[middle])
		{
			left = middle + 1 ;
		}
		if (x < a[middle])
		{
			right = middle - 1 ;
		}
		if (x == a[middle])
		{
			printf("查询了%d次\n", count);
			return middle;
		}
	}
	return -1;

}