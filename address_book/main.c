#include "contact.h"

//���˵�
void Menu()
{
	printf("\n\n############################################\n");
	printf("## 1������        2��ɾ��        3���޸�  ##\n");
	printf("## 4����ѯ        5����ʾ        6������  ##\n");
	printf("## 7������        8�����        0���˳�  ##\n");
	printf("############################################\n");
	printf("������ѡ��#\n");
}

int CheckInput(char a)//�������ѡ��
{
	if (a < '0' || a > '8')
		return 1;
	else
		return 0;
}

int main()
{ 
	book_p contact = NULL;//ͨѶ¼����
	InitContact(&contact);//�������ָ��
	int flag = 0;
	char select = 0;//�û������ѡ��
	while (!flag)
	{
		Menu();
		scanf(" %c", &select);
		if (CheckInput(select))//�������ѡ��
		{
			printf("����������������룡");
			fflush(stdin);
			continue;
		}
		switch (select-48){
		case 1:
			AddContact(&contact);//������Ա��Ϣ
			break;
		case 2:
			DelContact(contact);//ɾ����Ա��Ϣ
			break;
		case 3:
			ChangeContact(contact);//�޸���Ա��Ϣ
			break;
		case 4:
			FindContact(contact);//������Ա
			break;
		case 5:
			ShowContact(contact);//��ʾͨѶ¼����
			break;
		case 6:
			SortContact(contact);//��Ա����
			break;
		case 7:
			SaveContact(contact);//����ͨѶ¼
			break;
		case 8:
			ClearContact(contact);//���ͨѶ¼
			break;
		case 0:
			flag = 1;
			break;
		}
	}

	return 0;
}