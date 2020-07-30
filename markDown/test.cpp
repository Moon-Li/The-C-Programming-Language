#include "MarkDown.h"

void test()
{
	markdown wd("test.md");
	wd.transform();
	wd.createHtml();
}

int main()
{
	test();
	return 0;
}
