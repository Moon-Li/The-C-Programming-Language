#include"Game.h"

void InitBroad(char broad[ROW][COL], int row, int col)//初始化数组，全置为空格
{
	/*int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			broad[i][j] = ' ';
	}*/
	memset(&broad[0][0], ' ', row*col*sizeof(broad[0][0]));
}

void OutPut(char broad[ROW][COL], int row, int col)//输出棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", broad[i][j]);
			else
				printf(" %c ", broad[i][j]);
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---");
			}
		}
		printf("\n");
	}
}
char ComputerTurn(char broad[ROW][COL], int row, int col)//电脑下棋
{
	int x = 0;
	int y = 0;
	printf("电脑下：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (broad[x][y] == ' ')
		{
			broad[x][y] = 'X';
			break;
		}
	}
}

char PlayerTurn(char broad[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家下：\n");
		scanf("%d%d", &x, &y);

		if (x > 0 && x <= row  && y > 0 && y <= col)
		{
			if (broad[x-1][y-1] == ' ')
			{
				broad[x - 1][y - 1] = 'O';
				break;
			}
			else 
				printf("位置已被占用，请重新输入！\n");
		}
		else
			printf("超出棋盘范围，请重新输入：\n");
			
	}
}
char IfWin(char broad[ROW][COL], int row, int col)//判断胜负
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
				count++;
		}
	}
	for (i = 0; i < row; i++)
	{
		if (broad[i][0] == broad[i][1] &&
			broad[i][1] == broad[i][2] && broad[i][0] != ' ')
			return broad[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (broad[0][j] == broad[1][j] &&
			broad[0][j] == broad[2][j] && broad[0][j] != ' ')
			return broad[0][j];
	}
	if (broad[0][0] == broad[1][1] &&
		broad[1][1] == broad[2][2] && broad[1][1] != ' ')
		return broad[1][1];
	else if (count == 0)
		return 'P';

	return 0;
}
int Winner(win)
{
	if (win == 'X')
	{
		printf("电脑胜利啦！\n");
		return 1;
	}
	else if (win == 'O')
	{
		printf("玩家胜利啦！\n");
		return 1;
	}
	else if (win == 'P')
	{
		printf("平局！");
		return 1;
	}
	else
		return 0;
}