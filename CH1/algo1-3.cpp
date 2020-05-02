//algo1-3：C++中引用类型和非引用类型的区别
#include "c1.h"

void fa(int n)
{
	n++;
	printf("调用fa函数后，n = %d\n", n);
}

void fb(int& n)
{
	n++;
	printf("调用fb函数后，n = %d\n", n);
}

int main(void)
{
	int n = 1;
	printf("在主程序中，未调用任何函数之前 n = %d\n", n);
	fa(n);
	printf("主程序中调用fa之后n = %d\n", n);
	fb(n);
	printf("主程序中调用fb之后n = %d\n", n);
	return 0;
}