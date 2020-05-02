#include "c1.h"
typedef int ElemType;
#include "c2-2.h"
#include "bo2-2.cpp"

void Union(struct LNode * &La, struct LNode * &Lb)
{
	int len_a = ListLength(La);
	int len_b = ListLength(Lb);
	ElemType e;
	for (int i = 1; i<=len_b; i++)
	{
		GetElem(Lb, i, e);
		if (!locateElem(La, e))
		{
			ListInsert(La, ++len_a, e);
		}
	}
}

int main(void)
{
	struct LNode *La;
	InitList(La);
	for (int i = 1; i<=5; i++)
	{
		ListInsert(La, i, i);
	}
	ListTraverse(La);

	struct LNode *Lb;
	InitList(Lb);
	for (int j = 1; j<=5; j++)
	{
		ListInsert(Lb, j, j*2);	
	}
	ListTraverse(Lb);

	//´¦Àí
	Union(La, Lb);
	ListTraverse(La);

	return 0;
}