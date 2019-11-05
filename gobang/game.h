#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning (disable:4996)

#define ROW 15
#define COL 15

void InitBroad(char broad[ROW][COL], int row, int col);//��ʼ������
void OutPut(char broad[ROW][COL], int row, int col);//�������
char ComputerTurn(char broad[ROW][COL], int row, int col, int *a, int *b, char *letter);//��������
char Player1Turn(char broad[ROW][COL], int row, int col, int *a, int *b, char *letter);//���1����
char Player2Turn(char broad[ROW][COL], int row, int col, int *a, int *b, char *letter);//���2����
char IfWin(char broad[ROW][COL], int row, int col, int X, int Y, char *letter);//�ж�ʤ��
int Winner(win);
char five_x1(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�
char five_x2(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�

char five_x3(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�
char five_x4(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�

char five_x5(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�
char five_x6(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�

char five_x7(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�
char five_x8(char broad[ROW][COL], int x, int y, int *num, char *let);//�����ж�

#endif //__GAME_H__