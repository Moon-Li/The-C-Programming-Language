#ifndef __GAME_H__
#define __GAME_H__


#include<time.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

void InitBroad(char broad[ROW][COL], int row, int col);//初始化数组
void OutPut(char broad[ROW][COL], int row, int col);//输出棋盘
char ComputerTurn(char broad[ROW][COL], int row, int col);//电脑下棋
char PlayerTurn(char broad[ROW][COL], int row, int col);//玩家下棋
char IfWin(char broad[ROW][COL], int row, int col);//判断胜负
int Winner(win);

#endif //__GAME_H__