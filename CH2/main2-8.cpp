/*
 * 文件名：main2-8.cpp
 * 描  述：单链表，不带有头结点
 */

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-8.cpp"


int main(void)
{
	struct LNode *L;
	
	//初始化
	InitList(L);

	//插入
	for (int i = 1; i<=5; i++)
	{
		ListInsert(L, i, i);
	}

	//清空
	ClearList(L);

	//判空
	if (ListEmpty(L))
	{
		printf("为空！\n");
	}
	else
	{
		printf("非空！\n");
	}

	//指定位置插入
	for (int j = 1; j<=5; j++)
	{
		ListInsert(L, j, j);
	}
	
	//遍历
	ListTraverse(L);

	//第2个元素的值
	ElemType e;
	GetElem(L, 2, e);
	printf("第2个元素的值为：%d\n", e);

	//前驱
	ElemType pre_e;
	PriorElem(L, 3, pre_e);
	printf("“3”的前驱元素是：%d\n", pre_e);

	//后继
	ElemType next_e;
	NextElem(L, 3, next_e);
	printf("“3”的后继元素是：%d\n", next_e);

	//删除第2个元素
	ElemType del;
	ListDelete(L, 2, del);
	printf("第2个元素已经被删除，它的值是：%d\n", del);

	ListTraverse(L);
	
	//locateElem
	ElemType e1;
	printf("值为4的下标值为：%d\n", locateElem(L, 4));
	
	//销毁线性表
	DestroyList(L);
	
	return 0;
}