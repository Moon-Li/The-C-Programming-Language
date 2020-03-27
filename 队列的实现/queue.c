#include "queueh.h"

void queueInit(Queue* q)
{
	//空队列
	q->_front = NULL;
	q->_rear = NULL;
	q->_size = 0;
}

void queuePush(Queue* q, DataType data)
{
	//创建节点
	Node * node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	//尾插
	if (q->_front == NULL){
		q->_front = node;
		q->_rear = node;
	}
	else{
		q->_rear->_next = node;
	}
	q->_rear = node;
	q->_size++;
}

void queuePop(Queue* q)
{
	if (q->_front != NULL)
	{
		Node* next = q->_front->_next;
		//删除头节点
		free(q->_front);
		//更新头节点
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
		q->_size--;
	}
}

DataType queueFront(Queue* q)//队头元素
{
	return q->_front->_data;
}

DataType queueBack(Queue* q)//队尾元素
{
	return q->_rear->_data;
}

int queueEmpty(Queue* q)//队列是否为空
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

size_t queueSize(Queue* q)//队列大小
{
	return q->_size;
}

void queueDestory(Queue* q)//队列销毁
{
	Node* cur = q->_front;
	while (cur)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_rear = q->_front = NULL;
	q->_size = 0;
}