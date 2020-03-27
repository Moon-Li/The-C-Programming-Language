//˳���ʵ��ջ
#ifndef __STACKH_H__

#define __STACKH_H__

#include<stdio.h>
#include<malloc.h>
#include<windows.h>

typedef int DataType;//��������޸���������
typedef struct Stack
{
	DataType* _array;
	size_t _size;
	size_t _capacity;//����
}Stack;


void stackInit(Stack* st, size_t n);//ջ��ʼ��

void stackPush(Stack* st, DataType data);//����Ԫ��

void stackPop(Stack* st);//ɾ��Ԫ��

DataType stackTop(Stack* st);//��ȡջ��Ԫ��

size_t stackSize(Stack* st);//ջԪ�ظ���

int stackEmpty(Stack* st);//�ж�ջ�Ƿ�Ϊ��

void stackDestroy(Stack* st);//����ջ

#endif // !__stack_h_H__