typedef int ElemType;	//本程序用int作为基础数据类型
#include "c2-1.h"
#include "c1.h"
#include "bo2-1.cpp"

int main(void)
{
	struct sqList L;
	
	//初始化
	InitList(L);
	
	//倒序插入
	for (int j = 1; j <= 5; j++)
	{
		ListInsert(L, 1, j);
	}
	
	for (int i = 0; i<5; i++)
	{
		printf("%5d", L.elem[i]);
	}
	printf("\nlength = %d\n", L.length);

	//判空
	if (ListEmpty(L))
	{
		printf("为空！\n");
	}

	//清空
	ClearList(L);

	//正序插入
	for (int k = 1; k <= 5; k++)
	{
		ListInsert(L, k, k);
	}
	for (int m = 1; m <= 5; m++)
	{
		printf("%5d", L.elem[m-1]);
	}
	printf("\nlength = %d\n", L.length);

	//表头插入元素“0”
	ListInsert(L, 1, 100);
	for (int n = 1; n <= 6; n++)
	{
		printf("%5d", L.elem[n-1]);
	}
	printf("\nlength = %d\n", L.length);
	
	//获取某一个元素的值
	ElemType e;
	GetElem(L, 2, e);
	printf("第二个元素的值为：%d\n", e);

	//前驱
	ElemType pre_e;
	PriorElem(L, 3, pre_e);
	printf("元素“3”的前驱是：%d\n", pre_e);

	//后继
	ElemType next_e;
	NextElem(L, 3, next_e);
	printf("元素“3”的后继元素是：%d\n", next_e);

	//删除
	ElemType del;
	ListDelete(L, 3, del);
	printf("被删除的元素是：%d\n", del);
	
	//遍历
	ListTraverse(L);

	//查找
	printf("%d\n", locateElem(L, 4));

	//销毁
	DestroyList(L);
	return 0;
}
