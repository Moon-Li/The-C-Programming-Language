#include "stackh.h"

void stackInit(Stack* st, size_t n)//栈初始化
{
	st->_array = (DataType*)malloc(sizeof(DataType)* n);
	st->_size = 0;
	st->_capacity = n;

}

void stackPush(Stack* st, DataType data)//增加元素
{
	//检查容量
	if (st->_size == st->_capacity)
	{
		st->_array = (DataType)realloc(st->_array, sizeof(DataType)* 2 * st->_capacity);
		st->_capacity *= 2;
		printf("发生扩容\n");
	}
	st->_array[st->_size] = data;
	st->_size++;
}

void stackPop(Stack* st)//删除元素
{
	if (st->_size > 0)
	{
		st->_size--;
	}
}

DataType stackTop(Stack* st)//获取栈顶元素
{
	return st->_array[st->_size-1];
}

size_t stackSize(Stack* st)//栈元素个数
{
	return st->_size;
}

int stackEmpty(Stack* st)//判断栈是否为空
{
	if (st->_size == 0)
		return 1;
	return  0;
}

void stackDestroy(Stack* st)//销毁栈
{
	if (st->_array)
	{
		free(st->_array);
		st->_size = 0;
		st->_capacity = 0;
	}
}