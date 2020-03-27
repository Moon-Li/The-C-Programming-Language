#include "queueh.h"

void test()
{
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	while (queueEmpty(&q) != 1)
	{
		printf("%d %d\n", queueFront(&q), queueBack(&q));
		queuePop(&q);
	}
	queueDestory(&q);
}
int main()
{
	test();
	system("pause");
	return 0;
}