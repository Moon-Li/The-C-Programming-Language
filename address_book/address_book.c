#include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(book_p * p)
{
	*p = (book_p)malloc(sizeof(book_t)+sizeof(person_t)* DEFAULT);
	if (*p == NULL)
	{
		perror("malloc���ٿռ�ʧ�ܣ�");
		exit(1);
	}
	(*p)->max = DEFAULT;
	(*p)->size = 0;
}

//�ж�ͨѶ¼�Ƿ�����
static int IsFull(book_p p)
{
	return p->size == p->max ? 1 : 0;
}

//ͨѶ¼����
static int Inc(book_p *p)
{
	printf("�ռ䲻�㣬׼�����ݣ�%d\n", (*p)->max);
	int new_max = (*p)->max * FOLD;
	book_p new_book = (book_p)realloc(*p, sizeof(book_t)+sizeof(person_t)* new_max);
	if (NULL == new_book)
	{
		printf("����ʧ�ܣ�\n");
		return 0;
	}
	*p = new_book;
	(*p)->max = new_max;
	printf("���ݳɹ���%d\n",(*p)->max);
	return 1;

}

//������Ա��Ϣ
void AddContact(book_p *p)
{ 
	if (IsFull(*p) && !Inc(p))//1���ռ�û�� 2���ռ����ˣ��������ݳɹ�
	{//������ˣ��������ݣ��������ʧ�ܣ�������
		printf("�ռ䲻��������ʧ�ܣ�\n");
		return;
	}
	//���뵱ǰҪ�����Ա����Ϣ��ָ��
	person_p cp = &((*p)->porsen[(*p)->size]);
	printf("��������ϵ������# ");
	scanf("%s", cp->name);
	printf("��������ϵ���Ա�# ");
	scanf(" %s", &cp->sex);
	printf("��������ϵ������# ");
	scanf("%d", &cp->age);
	printf("��������ϵ�˵绰# ");
	scanf("%s", cp->phone);
	printf("��������ϵ�˵�ַ# ");
	scanf("%s", cp->address);
	(*p)->size++;
}
void ShowContact(book_p p)//��ʾͨѶ¼����
{
	if (p->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
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

void FindContact(book_p p)//������Ա
{
	char _name[NAME_SIZE];
	printf("������Ҫ��ѯ���˵�����# ");
	scanf("%s", _name);
	int i = 0;
	printf("----------------------------------------------------\n");
	for (; i < p->size; i++)
	{
		person_p cp = &p->porsen[i];
		if (!strcmp(cp->name, _name))//�ж������ַ�����С����ȷ���0
		{
			printf("| %s | %s | %d | %s | %s |\n", \
				cp->name, cp->sex, cp->age, cp->phone, cp->address);
			printf("----------------------------------------------------\n");
			return;
		}
	}
	printf("û�д��ˣ�\n");
}

static int IsEmpty(book_p p)
{
	return p->size == 0;
}

void DelContact(book_p p)//ɾ����Ա��Ϣ
{
	if (!p->size)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	char _name[NAME_SIZE];
	printf("��������Ҫɾ�����˵�����# ");
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
			memcpy(cp, &p->porsen[p->size - 1], sizeof(person_t));//�ṹ�岻��ֱ�Ӹ�ֵ������ʹ���ڴ濽��
			printf("������ɾ���ɹ���\n");
			break;
		}
	}
	p->size--;
}
void ClearContact(book_p p)//���ͨѶ¼
{
	p->size = 0;
}

static int CompName(const void *x, const void *y)
{
	person_p xp = (person_p)x;
	person_p yp = (person_p)y;
	return strcmp(xp->name, yp->name);
}

void SortContact(book_p p)//��Ա����
{
	if (p->size < 2) 
	{
		printf("����Ҫ����\n");
		return;
	}
	qsort(p->porsen, p->size, sizeof(person_t), CompName);
	printf("��������ɣ�\n");
}