#include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(book_p * p)
{
	FILE *fp = fopen(SAVE_FILE, "rb");
	if (fp == NULL)
	{
		*p = (book_p)malloc(sizeof(book_t)+sizeof(person_t)* DEFAULT);
		if (*p == NULL)
		{
			perror("malloc���ٿռ�ʧ�ܣ�\n");
			exit(1);
		}
		(*p)->max = DEFAULT;
		(*p)->size = 0;
		printf("��ʼ����ɣ��½����ĵ���\n");
		return;
	}
	book_t ct;
	fread(&ct, sizeof(book_t), 1, fp);
	*p = (book_p)malloc(sizeof(book_t)+sizeof(person_t)* (ct.size));
	if (*p == NULL)
	{
		perror("malloc���ٿռ����ļ�ʧ�ܣ�\n");
		exit(1);
	}
	//memcpy(*p, &ct, sizeof(ct));
	(*p)->max = ct.max;//p2
	(*p)->size = ct.size;
	fread((*p)->porsen, sizeof(person_t), ct.size, fp);
	printf("��ʼ����ɣ��Ѷ�ȡ��ʷ�ĵ���\n");
	fclose(fp);
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
	char _name[NAME_SIZE];
	int i = 0;
	printf("��������ϵ������# ");
	scanf("%s", _name);
	//�ж������Ƿ��Ѿ�����
	for (; i < (*p)->size; i++)
	{
		person_p sp = &(*p)->porsen[i];
		if (!strcmp(sp->name, _name))//�ж������ַ�����С����ȷ���0
		{
			printf("�����Ѵ��ڣ������ظ���ӣ�\n");
			printf("| %s | %s | %d | %s | %s |\n", \
				sp->name, sp->sex, sp->age, sp->phone, sp->address);
			return;
		}
	}
	person_p cp = &((*p)->porsen[(*p)->size]);
	memcpy(&cp->name, _name, NAME_SIZE);
	printf("��������ϵ���Ա�# ");
	scanf(" %s", cp->sex);
	printf("��������ϵ������# ");
	scanf("%d", &cp->age);
	printf("��������ϵ�˵绰# ");
	scanf("%s", cp->phone);
	printf("��������ϵ�˵�ַ# ");
	scanf("%s", cp->address);
	//����
	//memcpy(&(*p)->porsen[(*p)->size], &pp, sizeof(person_t));
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

void FindContact(book_p p)//������Ա,�ҵ�����1
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
	printf("���޴��ˣ�\n");
	return;
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

void ChangeContact(book_p p)//�޸���Ա��Ϣ
{
	char _name[NAME_SIZE];
	int i = 0;
	printf("������Ҫ�޸�������# ");
	scanf("%s", _name);
	//�ҵ�����
	for (; i < (p)->size; i++)
	{
		person_p sp = &(p)->porsen[i];
		if (!strcmp(sp->name, _name))//�ж������ַ�����С����ȷ���0
		{
			printf("���ҵ����ˣ�\n");
			printf("| %s | %s | %d | %s | %s |\n", \
				sp->name, sp->sex, sp->age, sp->phone, sp->address);
			printf("������Ҫ�޸�����#\n");
			printf("1������	 2���Ա�  3������  4���绰  5����ַ\n");
			int choose = 0;
			scanf("%d", &choose);
			switch (choose){
			case 1:{
					   printf("����и���#");
					   char new_name[NAME_SIZE];
					   scanf("%s", new_name);
					   memcpy(&sp->name, new_name, NAME_SIZE);
			}
				break;
			case 2:{
					   printf("����и���#");
					   char new_sex[SEX_SIZE];
					   scanf("%s", new_sex);
					   memcpy(&sp->sex, new_sex, SEX_SIZE);
			}
				break;
			case 3:{
					   printf("����и���#");
					   int new_age = 0;
					   scanf("%d", &new_age);
					   sp->age = new_age;
			}
				break;
			case 4:{
					   printf("����и���#");
					   char new_phone[PHONE_SIZE];
					   scanf("%s", new_phone);
					   memcpy(&sp->phone, new_phone, PHONE_SIZE);
			}
				break;
			case 5:{
					   printf("����и���#");
					   char new_address[ADDRESS_SIZE];
					   scanf("%s", new_address);
					   memcpy(&sp->address, new_address, ADDRESS_SIZE);
			}
			}
			return;
		}
	}
	printf("���޴��ˣ�\n");

}


void SaveContact(book_p p)//����ͨѶ¼
{
	FILE *fp = fopen(SAVE_FILE, "wb");
	if (fp == NULL)
	{
		printf("����ʧ��(���ļ�ʧ��)��\n");
		return;
	}

	fwrite(p, sizeof(book_t), 1, fp);
	fwrite(p->porsen, sizeof(person_t), p->size, fp);
	printf("�ļ�����ɹ���\n");
	fclose(fp);
}