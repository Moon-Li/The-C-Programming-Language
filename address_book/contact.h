#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#pragma warning (disable:4996)

//名字大小
#define NAME_SIZE 15
//性别大小
#define SEX_SIZE 10
//电话号大小
#define PHONE_SIZE 15
//地址大小
#define ADDRESS_SIZE 20
//初始化空间大小
#define DEFAULT 1
//空间扩容倍数
#define FOLD 2
//保存通讯录的文件
#define SAVE_FILE "save.bin"

//个人信息结构体类型
typedef struct person{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	int age;
	char phone[PHONE_SIZE];
	char address[ADDRESS_SIZE];
}person_t, *person_p;//个人信息结构体类型

//通讯录结构体类型
typedef struct book{
	int max;//通讯录总空间
	int size;//通讯录现已使用空间
	/**个人信息结构体类型的，柔性数组*/
	person_t porsen[0];
}book_t, *book_p;//通讯录结构体类型


void InitContact(book_p * p);//初始化通讯录
void AddContact(book_p * p);//插入人员信息
void ShowContact(book_p p);//显示通讯录内容
void DelContact(book_p p);//删除人员信息
void FindContact(book_p p);//查找人员
void ClearContact(book_p p);//清空通讯录
void SortContact(book_p p);//人员排序
void SaveContact(book_p p);//保存通讯录
void ChangeContact(book_p p);//修改人员信息


#endif