#include "stackh.h"

int test()
{
	Stack st; 
	stackInit(&st, 2);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	while (stackEmpty(&st) != 1){
		printf("±»É¾ÔªËØÎª%d\n", stackTop(&st));
		stackPop(&st);
	}


	return 0;
}
int main()
{
	test();
	system("pause");
	return 0;
}