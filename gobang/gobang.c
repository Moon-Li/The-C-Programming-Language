#include"Game.h"

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
int PlayerChoose()//���ģʽ������ģʽ��ѡ��
{
	printf("��ѡ��Ծ�ģʽ��\n");
	printf("1�����˶Ծ�    0���˻��Ծ�\n");
	printf("��ѡ��");
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


int X = 0;
int Y = 0;
char letterr;
void game()
{
	char win = ' ';
	char broad[ROW][COL] = { 0 };
	InitBroad(broad, ROW, COL);//��ʼ������
	int play = PlayerChoose();
	while (1)
	{
		system("cls");
		if (play == 1)
		{
			OutPut(broad, ROW, COL);//��ӡ����
			Player2Turn(broad, ROW, COL, &X, &Y, &letterr);//���1��
			system("cls");
		}
		else
		{
			ComputerTurn(broad, ROW, COL, &X, &Y, &letterr);//������
		}
		OutPut(broad, ROW, COL);//��ӡ����
		win = IfWin(broad, ROW, COL, X, Y, &letterr);//�ж�ʤ��
		if (win != 0)
		{
			system("cls");
			Winner(win);//���ʤ��
			OutPut(broad, ROW, COL);
			break;
		}
		Player1Turn(broad, ROW, COL, &X, &Y, &letterr);//���2��
		system("cls");
		OutPut(broad, ROW, COL);//��ӡ����
		win = IfWin(broad, ROW, COL, X, Y, &letterr);//�ж�ʤ��
		if (win != 0)
		{
			system("cls");
			Winner(win);//���ʤ��
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
	printf("��Ϸ������\n");

	system("pause");
	return 0;
}