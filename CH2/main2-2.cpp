/*
 * 文件名：main2-2.cpp
 * 功  能: 带有头结点的单链表
 */

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"

void main()
{
	struct LNode * L;			//struct LNode *类型，指向头节点的头指针
	InitList(L);

	//表头插入元素	

	for (int i = 1; i<=5; i++)
	{
		ListInsert(L, 1, i);		
	}

	//遍历
	ListTraverse(L);

	//判空
	if (ListEmpty(L))
	{
		printf("空！\n");
	}
	else
	{
		printf("非空！\n");
	}

	//清空
	ClearList(L);
	if (ListEmpty(L))
	{
		printf("空！\n");
	}
	else
	{
		printf("非空！\n");
	}

	//表尾插入
	for (int j = 1; j<=5; j++)
	{
		ListInsert(L, j, j);
	}
	ListTraverse(L);

	//获取指定下标对应元素的值
	ElemType m;
	GetElem(L, 3, m);
	printf("第“3”个元素是：%d\n", m);

	//前驱
	ElemType pre_e;
	//求元素“2”的前驱元素
	PriorElem(L, 2, pre_e);
	printf("元素“2”的前驱元素是：%d\n", pre_e);
	
	//后驱
	ElemType next_e;
	NextElem(L, 2, next_e);
	printf("元素“2”的后继元素是：%d\n", next_e);

	//求长度
	printf("表长为：%d\n", ListLength(L));

	//删除某个元素
	ElemType e;
	//删除第2个元素
	ListDelete(L, 2, e);
	printf("被删除的元素是：%d\n", e);
	ListTraverse(L);
	
	//在链表L中查找值为“3”的元素
	printf("值为“3”的元素的下标是：%d\n", locateElem(L, 3));

	//销毁链表
	DestoryList(L);
	ListTraverse(L);
}