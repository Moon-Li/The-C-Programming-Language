#ifndef __QUEUEH_H__
#define __QUEUEH_H__

#include<stdio.h>
#include<malloc.h>
#include<windows.h>
//带有尾指针的单链表实现队列

typedef int DataType;//重定义方便修改类型

typedef struct Node
{
	struct Node* _next;
	DataType _data;
}Node;

typedef struct Queue
{
	//头尾指针
	Node* _front;
	Node* _rear;
	size_t _size;
}Queue;

void queueInit(Queue* q);

void queuePush(Queue* q, DataType data);

void queuePop(Queue* q);

DataType queueFront(Queue* q);//队头元素

DataType queueBack(Queue* q);//队尾元素

int queueEmpty(Queue* q);//队列是否为空

size_t queueSize(Queue* q);//队列大小

void queueDestory(Queue* q);//队列销毁



#endif // !__QUEUEH_H__