#include "stackh.h"

void stackInit(Stack* st, size_t n)//ջ��ʼ��
{
	st->_array = (DataType*)malloc(sizeof(DataType)* n);
	st->_size = 0;
	st->_capacity = n;

}

void stackPush(Stack* st, DataType data)//����Ԫ��
{
	//�������
	if (st->_size == st->_capacity)
	{
		st->_array = (DataType)realloc(st->_array, sizeof(DataType)* 2 * st->_capacity);
		st->_capacity *= 2;
		printf("��������\n");
	}
	st->_array[st->_size] = data;
	st->_size++;
}

void stackPop(Stack* st)//ɾ��Ԫ��
{
	if (st->_size > 0)
	{
		st->_size--;
	}
}

DataType stackTop(Stack* st)//��ȡջ��Ԫ��
{
	return st->_array[st->_size-1];
}

size_t stackSize(Stack* st)//ջԪ�ظ���
{
	return st->_size;
}

int stackEmpty(Stack* st)//�ж�ջ�Ƿ�Ϊ��
{
	if (st->_size == 0)
		return 1;
	return  0;
}

void stackDestroy(Stack* st)//����ջ
{
	if (st->_array)
	{
		free(st->_array);
		st->_size = 0;
		st->_capacity = 0;
	}
}