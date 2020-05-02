/*
 * 文件名：c2-4.h
 * 功  能：有头结点的双向循环链表的结构体文件
 */

struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
};
