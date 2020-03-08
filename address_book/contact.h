#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#pragma warning (disable:4996)

//���ִ�С
#define NAME_SIZE 15
//�Ա��С
#define SEX_SIZE 10
//�绰�Ŵ�С
#define PHONE_SIZE 15
//��ַ��С
#define ADDRESS_SIZE 20
//��ʼ���ռ��С
#define DEFAULT 1
//�ռ����ݱ���
#define FOLD 2
//����ͨѶ¼���ļ�
#define SAVE_FILE "save.bin"

//������Ϣ�ṹ������
typedef struct person{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	int age;
	char phone[PHONE_SIZE];
	char address[ADDRESS_SIZE];
}person_t, *person_p;//������Ϣ�ṹ������

//ͨѶ¼�ṹ������
typedef struct book{
	int max;//ͨѶ¼�ܿռ�
	int size;//ͨѶ¼����ʹ�ÿռ�
	/**������Ϣ�ṹ�����͵ģ���������*/
	person_t porsen[0];
}book_t, *book_p;//ͨѶ¼�ṹ������


void InitContact(book_p * p);//��ʼ��ͨѶ¼
void AddContact(book_p * p);//������Ա��Ϣ
void ShowContact(book_p p);//��ʾͨѶ¼����
void DelContact(book_p p);//ɾ����Ա��Ϣ
void FindContact(book_p p);//������Ա
void ClearContact(book_p p);//���ͨѶ¼
void SortContact(book_p p);//��Ա����
void SaveContact(book_p p);//����ͨѶ¼
void ChangeContact(book_p p);//�޸���Ա��Ϣ


#endif