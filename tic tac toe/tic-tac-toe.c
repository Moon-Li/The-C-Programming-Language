#include<stdio.h>
#include<windows.h>
#include"Game.h"
#pragma warning (disable:4996)

void menu()//游戏初始界面
{
	printf("*******************************\n");
	printf("*********    1.play    ********\n");
	printf("*********    0.exit    ********\n");
	printf("*******************************\n");
}

int work()//判断游戏是否进行
{
	printf("是否开始一轮新的游戏：");
	while (1)
	{
		int i = 0;
		scanf("%d", &i);
		if (i == 1)
			return 1;
		else if (i == 0)
			return 0;
		else
			printf("输入错误，请重新输入：");
	}
}


void game()
{
	char win = ' ';
	char broad[ROW][COL] = {0};
	InitBroad(broad, ROW, COL);//初始化棋盘
	while (1)
	{
		ComputerTurn(broad, ROW, COL);//电脑下
		OutPut(broad, ROW, COL);//打印棋盘
		win = IfWin(broad, ROW, COL);//判断胜负
		if (win != 0)
		{
			OutPut(broad, ROW, COL);
			break;
		}
		PlayerTurn(broad, ROW, COL);//玩家下
		OutPut(broad, ROW, COL);//打印棋盘
		if (win != 0) //判断胜负
		{
			OutPut(broad, ROW, COL);
			break;
		}
	}
	Winner(win);//输出胜者
}

int main()
{
	srand((unsigned)time(NULL));
	while (1)
	{
		menu();
		if (work())
			game();
		else
			break;
	}
	printf("游戏结束！\n");

	system("pause");
	return 0;
}