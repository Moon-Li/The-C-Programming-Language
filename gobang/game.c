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
	for (i = 0; i <= row; i++)
	{
		printf("%2d  ", i);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%2d ", i + 1);
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
			printf("   ");
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
char ComputerTurn(char broad[ROW][COL], int row, int col, int *a, int *b, char *letter)//电脑下棋
{
	int x = 0;
	int y = 0;
	*a = 0;
	*b = 0;
	printf("电脑下：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (broad[x][y] == ' ')
		{
			broad[x][y] = 'X';
			*letter = 'X';
			*a = x;
			*b = y;
			break;
		}
	}
	return 0;
}

char Player1Turn(char broad[ROW][COL], int row, int col, int *a, int *b, char *letter)//玩家下棋
{
	int x = 0;
	int y = 0;
	*a = 0;
	*b = 0;
	while (1)
	{
		printf("玩家1下：\n");
		scanf("%d%d", &x, &y);

		if (x > 0 && x <= row  && y > 0 && y <= col)
		{
			if (broad[x - 1][y - 1] == ' ')
			{
				broad[x - 1][y - 1] = 'Q';
				*letter = 'Q';
				*a = x - 1;
				*b = y - 1;
				printf("%c\n", broad[x - 1][y - 1]);
				break;
			}
			else
				printf("位置已被占用，请重新输入！\n");
		}
		else
			printf("超出棋盘范围，请重新输入：\n");

	}
	return 0;
}

char Player2Turn(char broad[ROW][COL], int row, int col,int *a,int *b, char *letter)//玩家下棋
{
	int x = 0;
	int y = 0;
	*a = 0;
	*b = 0;
	while (1)
	{
		printf("玩家2下：\n");
		scanf("%d%d", &x, &y);

		if (x > 0 && x <= row  && y > 0 && y <= col)
		{
			if (broad[x - 1][y - 1] == ' ')
			{
				broad[x - 1][y - 1] = 'W';
				*letter = 'W';
				*a = x - 1;
				*b = y - 1;
				printf("%c\n", broad[x - 1][y - 1]);
				break;
			}
			else
				printf("位置已被占用，请重新输入！\n");
		}
		else
			printf("超出棋盘范围，请重新输入：\n");

	}
	return 0;
}
char IfWin(char broad[ROW][COL], int row, int col, int x, int y, char *letter)//判断胜负
{
	int i = 0;
	int j = 0;
	char let = *letter;
	int count_num = 1;
	char arr[ROW][COL];
	int count = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] =broad[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
			{
				count++;
				break;
			}
		}
		if (count != 0)
			break;
	}
	if (count == 0)
		return 'P';//平
	//胜利情况
	char vin1 = five_x1(arr, x, y, &count_num, &let);
	char vin2 = five_x2(arr, x, y, &count_num, &let);
	char vinA = vin1 > vin2 ? vin1 : vin2;
	if (vinA > 0)//纵向胜利
		return vinA;

	count_num = 1;
	char vin3 = five_x3(arr, x, y, &count_num, &let);
	char vin4 = five_x4(arr, x, y, &count_num, &let);
	char vinB = vin3 > vin4 ? vin3 : vin4;
	if (vinB > 0)//横向胜利
		return vinB;

	count_num = 1;
	char vin5 = five_x5(arr, x, y, &count_num, &let);
	char vin6 = five_x6(arr, x, y, &count_num, &let);
	char vinC = vin5 > vin6 ? vin5 : vin6;
	if (vinC > 0)//左上向胜利
		return vinC; 
	char vin7 = five_x7(arr, x, y, &count_num, &let);
	char vin8 = five_x8(arr, x, y, &count_num, &let);
	char vinD = vin7 > vin8 ? vin7 : vin8;
	if (vinD > 0)//右上胜利
		return vinD;

	return 0;
}
char five_x1(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (x == 0 ||x == 14)
	{
		if (broad[x][y] == *let)
		(*num)++;
	}*/
	if (x != 0 || x != 14)
	{
		for (x = x - 1; x > x - 5; x--)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (x == 0)
					break;
			}
			else
				break;
		}
	}
	return 0;
}
char five_x2(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (x == 14)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (x != 14)
	{
		for (x = x + 1; x < x + 5; x++)
		{
			if (broad[x][y] == *let)
			{
				if (x == 14)
					break;
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				
			}
			else
				break;
		}
	}
	return 0;
}

char five_x3(char broad[ROW][COL], int x, int y, int* num, char* let)
{
	/*if (y == 0)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (y != 0 || y != 14)

	{
		for (y = y - 1; y > y - 5; y--)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (y == 0)
					break;
			}
			else
				break;
		}
	}
	return 0;
}
char five_x4(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (y == 14)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (y != 14)
	{
		for (y = y + 1; y < y + 5; y++)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (y == 14)
					break;
			}
			else
				break;
		}
	}
	return 0;
}

char five_x5(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (y == 0 || x == 0)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (y != 14 || x != 14 || y != 0 || x != 0)
	{
		for (x = x - 1, y = y - 1; x > x - 5, y > y - 5; x--, y--)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (y == 0 || x == 0)
					break;
			}
			else
				break;
		}
	}
	return 0;
}
char five_x6(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (y == 14 || x == 14)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (y != 14 || x != 14)
	{
		for (x = x + 1, y = y + 1; x < x + 5, y < y + 5; x++, y++)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (y == 14 || x == 14)
					break;
			}
			else
				break;
		}
	}
	return 0;
}

char five_x7(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (y == 14 || x == 0)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (y != 0 || x != 14 || y != 14 || x != 0)
	{
		for (x = x - 1, y = y + 1; x > x - 5, y < y + 5; x--, y++)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (y == 14 || x == 0)
					break;
			}
			else
				break;
		}
	}
	return 0;
}
char five_x8(char broad[ROW][COL], int x, int y, int* num, char *let)
{
	/*if (y == 0 || x == 14)
	{
		if (broad[x][y] == *let)
			(*num)++;
	}*/
	if (y != 0 || x != 14)
	{
		for (x = x + 1, y = y - 1; x < x + 5, y > y - 5; x++, y--)
		{
			if (broad[x][y] == *let)
			{
				(*num)++;
				if (*num > 4)
				{
					return *let;
				}
				if (y == 0 || x == 14)
					break;
			}
			else
				break;
		}
	}
	return 0;
}

int Winner(win)
{
	if (win == 'X')
	{
		printf("电脑胜利啦！\n");
		return 1;
	}
	else if (win == 'Q')
	{
		printf("玩家1胜利啦！\n");
		return 1;
	}
	else if (win == 'W')
	{
		printf("玩家2胜利啦！\n");
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
