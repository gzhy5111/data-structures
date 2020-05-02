#include "c1.h"
typedef int ElemType;
#include "c1-1.h"
#include "bo1-1.cpp"

void main()
{
	Triplet T;	//T是指针变量类型
	//初始化
	InitTriplet(T, 5, 7, 9);
	printf("%d %d %d\n", T[0], T[1], T[2]);

	//Get
	ElemType m;			//int型
	Get(T, 1, m);		//m使用了引用
	printf("下标为1的元素是：%d\n", m);

	//Put
	Put(T, 2, 6);		//将第二个值改为6
	printf("%d %d %d\n", T[0], T[1], T[2]);

	//判断升序
	if (IsAscending(T))
	{
		printf("升序！\n");
	}

	//判断降序
	if (IsDescending(T))
	{
		printf("降序！\n");
	}

	//最大值
	ElemType max;
	Max(T, max);
	printf("max = %d\n", max);

	//最小值
	ElemType min;
	Min(T, min);
	printf("min = %d\n", min);

	//销毁
	if (Destroy(T))
	{
		printf("销毁成功！\n");
	}
}