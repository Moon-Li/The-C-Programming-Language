#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

//int main()//判断凶手
//{
//	int killer = 0;
//	for (killer = 1; killer <= 4; killer++)
//	{
//		if (3 == (killer != 1) + (killer == 3) + (killer == 4) + (killer != 4))
//			printf("凶手是：%d号\n", killer);
//	}
//
//	system("pause");
//	return 0;
//}

int main()//五个运动员跳水
{
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1;	B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if ((A == 3) + (B == 2) == 1
							&& (B == 2) + (E == 4) == 1
							&& (C == 1) + (D == 2) == 1
							&& (C == 5) + (D == 3) == 1
							&& (E == 4) + (A == 1) == 1)
						{
							if(A*B*C*D*E == 120)
							printf("第一名：%d\n第二名：%d\n第三名：%d\n第四名：%d\n第五名：%d\n", A, B, C, D, E);
						}
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}