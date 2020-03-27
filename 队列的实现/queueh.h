#ifndef __QUEUEH_H__
#define __QUEUEH_H__

#include<stdio.h>
#include<malloc.h>
#include<windows.h>
//����βָ��ĵ�����ʵ�ֶ���

typedef int DataType;//�ض��巽���޸�����

typedef struct Node
{
	struct Node* _next;
	DataType _data;
}Node;

typedef struct Queue
{
	//ͷβָ��
	Node* _front;
	Node* _rear;
	size_t _size;
}Queue;

void queueInit(Queue* q);

void queuePush(Queue* q, DataType data);

void queuePop(Queue* q);

DataType queueFront(Queue* q);//��ͷԪ��

DataType queueBack(Queue* q);//��βԪ��

int queueEmpty(Queue* q);//�����Ƿ�Ϊ��

size_t queueSize(Queue* q);//���д�С

void queueDestory(Queue* q);//��������



#endif // !__QUEUEH_H__