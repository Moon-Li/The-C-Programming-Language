#ifndef __GAME_H__
#define __GAME_H__


#include<time.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

void InitBroad(char broad[ROW][COL], int row, int col);//��ʼ������
void OutPut(char broad[ROW][COL], int row, int col);//�������
char ComputerTurn(char broad[ROW][COL], int row, int col);//��������
char PlayerTurn(char broad[ROW][COL], int row, int col);//�������
char IfWin(char broad[ROW][COL], int row, int col);//�ж�ʤ��
int Winner(win);

#endif //__GAME_H__