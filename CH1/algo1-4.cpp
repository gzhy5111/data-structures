//exit()函数的作用：退出程序的运行
#include "c1.h"

int a(int i)
{
	if (i == 1)
	{
		printf("退出程序的运行！\n");
		exit(1);
	}
	return i;
}

int main(void)
{
	int i;
	scanf("%d", &i);
	printf("i = %d\n", a(i));
	return 0;
}