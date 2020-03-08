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

int CheckInput(char a)//检查输入选项
{
	if (a < '0' || a > '8')
		return 1;
	else
		return 0;
}

int main()
{ 
	book_p contact = NULL;//通讯录主体
	InitContact(&contact);//传入二级指针
	int flag = 0;
	char select = 0;//用户输入的选项
	while (!flag)
	{
		Menu();
		scanf(" %c", &select);
		if (CheckInput(select))//检查输入选项
		{
			printf("输入错误！请重新输入！");
			fflush(stdin);
			continue;
		}
		switch (select-48){
		case 1:
			AddContact(&contact);//插入人员信息
			break;
		case 2:
			DelContact(contact);//删除人员信息
			break;
		case 3:
			ChangeContact(contact);//修改人员信息
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
			SaveContact(contact);//保存通讯录
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