/*
 * 文件名：main2-4.cpp
 * 描  述：含有头结点和尾指针(L)形式的单循环链表
 */

#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-4.cpp"

int main(void)
{
	struct LNode *L;
	InitList(L);

	//长度
	printf("单循环链表的长度是：%d\n", ListLength(L));

	//插入
	ListInsert(L, 1, 1);
	printf("单循环链表的长度是：%d\n", ListLength(L));
	ListInsert(L, 1, 2);
	printf("单循环链表的长度是：%d\n", ListLength(L));
	
	//判空
	if (ListLength(L) == 0)
	{
		printf("为空\n");
	}
	else
	{
		printf("非空！\n");
	}

	//清空
	ListClear(L);

	//插入

	ListInsert(L, 1, 1);	
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);


	//遍历
	ListTraverse(L);

	//前驱
	ElemType pre_e;
	PriorElem(L, 2, pre_e);
	printf("元素2的前驱值是：%d\n", pre_e);

	//后驱
	ElemType next_e;
	NextElem(L, 1, next_e);
	printf("元素1的后继值是：%d\n", next_e);

	//查找
	//查找下标为1的元素
	ElemType e0;
	GetElem(L, 2, e0);
	printf("下标为2的元素是：%d\n", e0);

	//删除
	//删除第2个元素
	ElemType e;
	ListDelete(L, 2, e);
	printf("被删除的元素是：%d\n", e);
	ListTraverse(L);

	//查询 locateElem
	printf("元素1的下标是：%d\n", locateElem(L, 1));
	
	//销毁
	ListDestroy(L);
	return 0;
}