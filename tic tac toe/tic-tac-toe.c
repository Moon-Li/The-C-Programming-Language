#include<stdio.h>
#include<windows.h>
#include"Game.h"
#pragma warning (disable:4996)

void menu()//��Ϸ��ʼ����
{
	printf("*******************************\n");
	printf("*********    1.play    ********\n");
	printf("*********    0.exit    ********\n");
	printf("*******************************\n");
}

int work()//�ж���Ϸ�Ƿ����
{
	printf("�Ƿ�ʼһ���µ���Ϸ��");
	while (1)
	{
		int i = 0;
		scanf("%d", &i);
		if (i == 1)
			return 1;
		else if (i == 0)
			return 0;
		else
			printf("����������������룺");
	}
}


void game()
{
	char win = ' ';
	char broad[ROW][COL] = {0};
	InitBroad(broad, ROW, COL);//��ʼ������
	while (1)
	{
		ComputerTurn(broad, ROW, COL);//������
		OutPut(broad, ROW, COL);//��ӡ����
		win = IfWin(broad, ROW, COL);//�ж�ʤ��
		if (win != 0)
		{
			OutPut(broad, ROW, COL);
			break;
		}
		PlayerTurn(broad, ROW, COL);//�����
		OutPut(broad, ROW, COL);//��ӡ����
		if (win != 0) //�ж�ʤ��
		{
			OutPut(broad, ROW, COL);
			break;
		}
	}
	Winner(win);//���ʤ��
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
	printf("��Ϸ������\n");

	system("pause");
	return 0;
}