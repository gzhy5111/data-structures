#include "c1.h"

int main(void)
{
	int n = 3;
	int x = 1;
	double sum = 0;	//×Ü¼Æ
	double sum1 = 1;
	for (int i = 1; i <= n; i++)
	{
		sum1 = sum1 + sum1*(-1.0/x);
	}
	sum = sum+sum1;
	printf("sum = %lf\n", sum);
	return 0;
}