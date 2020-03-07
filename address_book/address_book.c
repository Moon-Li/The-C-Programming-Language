#include "contact.h"

//初始化通讯录
void InitContact(book_p * p)
{
	*p = (book_p)malloc(sizeof(book_t)+sizeof(person_t)* DEFAULT);
	if (*p == NULL)
	{
		perror("malloc开辟空间失败！");
		exit(1);
	}
	(*p)->max = DEFAULT;
	(*p)->size = 0;
}

//判断通讯录是否满了
static int IsFull(book_p p)
{
	return p->size == p->max ? 1 : 0;
}

//通讯录扩容
static int Inc(book_p *p)
{
	printf("空间不足，准备扩容！%d\n", (*p)->max);
	int new_max = (*p)->max * FOLD;
	book_p new_book = (book_p)realloc(*p, sizeof(book_t)+sizeof(person_t)* new_max);
	if (NULL == new_book)
	{
		printf("扩容失败！\n");
		return 0;
	}
	*p = new_book;
	(*p)->max = new_max;
	printf("扩容成功！%d\n",(*p)->max);
	return 1;

}

//插入人员信息
void AddContact(book_p *p)
{ 
	if (IsFull(*p) && !Inc(p))//1、空间没满 2、空间满了，但是扩容成功
	{//如果满了，进行扩容，如果扩容失败，出错返回
		printf("空间不足且扩容失败！\n");
		return;
	}
	//插入当前要添加人员的信息，指针
	person_p cp = &((*p)->porsen[(*p)->size]);
	printf("请输入联系人名字# ");
	scanf("%s", cp->name);
	printf("请输入联系人性别# ");
	scanf(" %s", &cp->sex);
	printf("请输入联系人年龄# ");
	scanf("%d", &cp->age);
	printf("请输入联系人电话# ");
	scanf("%s", cp->phone);
	printf("请输入联系人地址# ");
	scanf("%s", cp->address);
	(*p)->size++;
}
void ShowContact(book_p p)//显示通讯录内容
{
	if (p->size == 0)
	{
		printf("通讯录为空！\n");
		return;
	}
	printf("----------------------------------------------------\n");
	int i = 0;
	for (; i < p->size; i++)
	{
		person_p cp = &p->porsen[i];
		printf("| %s | %s | %d | %s | %s |\n", \
			cp->name, cp->sex, cp->age, cp->phone, cp->address);
		printf("----------------------------------------------------\n");
	}
}

void FindContact(book_p p)//查找人员
{
	char _name[NAME_SIZE];
	printf("请输入要查询的人的姓名# ");
	scanf("%s", _name);
	int i = 0;
	printf("----------------------------------------------------\n");
	for (; i < p->size; i++)
	{
		person_p cp = &p->porsen[i];
		if (!strcmp(cp->name, _name))//判断两个字符串大小，相等返回0
		{
			printf("| %s | %s | %d | %s | %s |\n", \
				cp->name, cp->sex, cp->age, cp->phone, cp->address);
			printf("----------------------------------------------------\n");
			return;
		}
	}
	printf("没有此人！\n");
}

static int IsEmpty(book_p p)
{
	return p->size == 0;
}

void DelContact(book_p p)//删除人员信息
{
	if (!p->size)
	{
		printf("通讯录为空！\n");
		return;
	}
	char _name[NAME_SIZE];
	printf("请输入你要删除的人的姓名# ");
	scanf("%s", _name);
	int i = 0;
	for (; i < p->size; i++)
	{
		person_p cp = &p->porsen[i];
		if (!strcmp(cp->name, _name))
		{
			printf("----------------------------------------------------\n");
			printf("| %s | %s | %d | %s | %s |\n", \
				cp->name, cp->sex, cp->age, cp->phone, cp->address);
			printf("----------------------------------------------------\n");
			memcpy(cp, &p->porsen[p->size - 1], sizeof(person_t));//结构体不能直接赋值，所以使用内存拷贝
			printf("此人已删除成功！\n");
			break;
		}
	}
	p->size--;
}
void ClearContact(book_p p)//清空通讯录
{
	p->size = 0;
}

static int CompName(const void *x, const void *y)
{
	person_p xp = (person_p)x;
	person_p yp = (person_p)y;
	return strcmp(xp->name, yp->name);
}

void SortContact(book_p p)//人员排序
{
	if (p->size < 2) 
	{
		printf("不需要排序！\n");
		return;
	}
	qsort(p->porsen, p->size, sizeof(person_t), CompName);
	printf("排序已完成！\n");
}