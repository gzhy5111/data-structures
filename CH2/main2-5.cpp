/*
 * 文件名：main2-5.cpp
 * 功  能：带有头结点的双向循环链表主函数文件
 */
typedef int ElemType;
#include "c1.h"
#include "c2-4.h"
#include "bo2-5.cpp"



int main(void)
{
	struct DuLNode *L;
	ListInit(L);

	//ListLength
	printf("链表长度为：%d\n", ListLength(L));

	//ListInsert(链表头指针,pos,值)
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);

	//正序输出链表
	printf("正序输出链表：");
	ListTraverse(L);
	
	//倒序输出链表
	printf("倒序输出链表：");
 	ListTraverseBack(L);

	//ListDelete
	ElemType e;
	ListDelete(L, 2, e);
	printf("被删除的元素是：%d\n", e);

	//判空
	if (ListEmpty(L))
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表非空\n");
	}

	//清空
	ClearList(L);

	//判空
	printf("\n清空后，链表是否为空：");
	if (ListEmpty(L))
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表非空\n");
	}

	//ListInsert
	for (int i = 1; i<=5; i++)
	{
		ListInsert(L, i, i);
	}
	ListTraverse(L);

	//GetElem() 当第i个元素存在时，赋值给e1
	ElemType e1;
	GetElem(L,1,e1);
	printf("第1个元素的值是：%d\n", e1);

	//LocateElem，找值为“3”的元素，返回下标（从0开始）
	printf("值为“3”的元素的下标为：%d\n", LocateElem(L, 3));
	
	//前序（找元素“2”的先序）
	ElemType e2;
	PriorElem(L, 2, e2);
	printf("“2”的前序元素是：%d\n", e2);

	//后序
	ElemType e3;
	NextElem(L, 2, e3);
	printf("“2”的后序元素是：%d\n", e3);	

	//销毁
	DestroyList(L);
	return 0;
}




