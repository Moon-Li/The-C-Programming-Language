//顺序表实现栈
#ifndef __STACKH_H__

#define __STACKH_H__

#include<stdio.h>
#include<malloc.h>
#include<windows.h>

typedef int DataType;//方便后面修改数据类型
typedef struct Stack
{
	DataType* _array;
	size_t _size;
	size_t _capacity;//容量
}Stack;


void stackInit(Stack* st, size_t n);//栈初始化

void stackPush(Stack* st, DataType data);//增加元素

void stackPop(Stack* st);//删除元素

DataType stackTop(Stack* st);//获取栈顶元素

size_t stackSize(Stack* st);//栈元素个数

int stackEmpty(Stack* st);//判断栈是否为空

void stackDestroy(Stack* st);//销毁栈

#endif // !__stack_h_H__