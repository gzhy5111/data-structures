typedef int ElemType;
#include "c1.h"
#include "c2-1.h"
#include "bo2-1.cpp"

void Union(struct sqList &La, struct sqList Lb)
{
	int len_a = La.length;
	int len_b = Lb.length;
	ElemType e;
	for (int i =1; i<=len_b; i++)
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
	struct sqList La;
	InitList(La);
	for (int i = 1; i<=5; i++)
	{
		ListInsert(La, i, i);		
	}
	ListTraverse(La);

	struct sqList Lb;
	InitList(Lb);
	for (int j = 1; j<=5; j++)
	{
		ListInsert(Lb, j, j*2);		
	}
	ListTraverse(Lb);

	//在Lb中找La中没有的元素并合并在La中
	Union(La, Lb);
	ListTraverse(La);

	return 0;
}