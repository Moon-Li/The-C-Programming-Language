#include"Game.h"

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
int PlayerChoose()//玩家模式，电脑模式，选择
{
	printf("请选择对局模式：\n");
	printf("1、人人对决    0、人机对决\n");
	printf("请选择：");
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


int X = 0;
int Y = 0;
char letterr;
void game()
{
	char win = ' ';
	char broad[ROW][COL] = { 0 };
	InitBroad(broad, ROW, COL);//初始化棋盘
	int play = PlayerChoose();
	while (1)
	{
		system("cls");
		if (play == 1)
		{
			OutPut(broad, ROW, COL);//打印棋盘
			Player2Turn(broad, ROW, COL, &X, &Y, &letterr);//玩家1下
			system("cls");
		}
		else
		{
			ComputerTurn(broad, ROW, COL, &X, &Y, &letterr);//电脑下
		}
		OutPut(broad, ROW, COL);//打印棋盘
		win = IfWin(broad, ROW, COL, X, Y, &letterr);//判断胜负
		if (win != 0)
		{
			system("cls");
			Winner(win);//输出胜者
			OutPut(broad, ROW, COL);
			break;
		}
		Player1Turn(broad, ROW, COL, &X, &Y, &letterr);//玩家2下
		system("cls");
		OutPut(broad, ROW, COL);//打印棋盘
		win = IfWin(broad, ROW, COL, X, Y, &letterr);//判断胜负
		if (win != 0)
		{
			system("cls");
			Winner(win);//输出胜者
			OutPut(broad, ROW, COL);
			break;
		}
	}
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