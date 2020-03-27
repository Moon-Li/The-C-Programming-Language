#include "queueh.h"

void queueInit(Queue* q)
{
	//�ն���
	q->_front = NULL;
	q->_rear = NULL;
	q->_size = 0;
}

void queuePush(Queue* q, DataType data)
{
	//�����ڵ�
	Node * node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	//β��
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
		//ɾ��ͷ�ڵ�
		free(q->_front);
		//����ͷ�ڵ�
		q->_front = next;
		if (q->_front == NULL)
			q->_rear = NULL;
		q->_size--;
	}
}

DataType queueFront(Queue* q)//��ͷԪ��
{
	return q->_front->_data;
}

DataType queueBack(Queue* q)//��βԪ��
{
	return q->_rear->_data;
}

int queueEmpty(Queue* q)//�����Ƿ�Ϊ��
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

size_t queueSize(Queue* q)//���д�С
{
	return q->_size;
}

void queueDestory(Queue* q)//��������
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