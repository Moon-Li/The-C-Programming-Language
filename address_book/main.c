#include "contact.h"

//主菜单
void Menu()
{
	printf("\n\n############################################\n");
	printf("## 1、增添        2、删除        3、修改  ##\n");
	printf("## 4、查询        5、显示        6、排序  ##\n");
	printf("## 7、保存        8、清空        0、退出  ##\n");
	printf("############################################\n");
	printf("请输入选择#\n");
}

int main()
{ 
	book_p contact = NULL;//通讯录主体
	InitContact(&contact);
	int flag = 0;
	int select = 0;//用户输入的选项
	while (!flag)
	{
		Menu();
		scanf("%d", &select);
		switch (select){
		case 1:
			AddContact(&contact);//插入人员信息
			break;
		case 2:
			DelContact(contact);//删除人员信息
			break;
		case 3:
			break;
		case 4:
			FindContact(contact);//查找人员
			break;
		case 5:
			ShowContact(contact);//显示通讯录内容
			break;
		case 6:
			SortContact(contact);//人员排序
			break;
		case 7:
			break;
		case 8:
			ClearContact(contact);//清空通讯录

			break;
		case 0:
			flag = 1;
			break;
		}
	}

	return 0;
}