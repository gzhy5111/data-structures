void InitList(struct sqList& L)
{
	L.elem = (ElemType *)malloc(10*sizeof(ElemType));
	if (NULL == L.elem)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	L.length = 0;
	L.listsize = 10;
}

void DestroyList(struct sqList& L)
{
	L.elem = NULL;
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
}

void ListInsert(struct sqList& L, int pos, int m)	//pos从1开始计数
{
	ElemType *q = L.elem+pos-1;
	ElemType *p = L.elem+L.length-1;
	for (p; p >= q; --p)
	{
		*(p+1) = *p;		//后移
	}
	*q = m;
	++L.length;
}

void ListDelete(struct sqList& L, int pos, int& e)
{
	ElemType *p = L.elem+pos-1;
	ElemType *q = L.elem+L.length-1;
	e = *p;
	for (p; p <= q; ++p)
	{
		*(p) = *(p+1);
	}
	--L.length;

}

bool ListEmpty(struct sqList& L)
{
	if (L.length == 0)
	{
		return 1;
	}
	return 0;
}

void ClearList(struct sqList& L)
{
	//将其length置为0即可。不用管malloc中的数据是否清空。
	L.length = 0;
}

void GetElem(struct sqList& L, int pos, int& e)
{
	e = L.elem[pos-1];
}

void PriorElem(struct sqList& L, ElemType cur_e, ElemType& pre_e)
{
	int i = 2;						//指向第二个元素
	ElemType *p = L.elem+1;			//指向第二个元素
	while (i <= L.length && *p != cur_e)
	{
		i++;
		p++;
	}
	if (i>L.length)
	{
		printf("越界！\n");
	}
	pre_e = *(p-1);
}

void NextElem(struct sqList& L, ElemType cur_e, ElemType& next_e)
{
	int i = 1;
	ElemType *p = L.elem;
	while (i <= L.length-1 && *p != cur_e)
	{
		p++;
		i++;
	}
	if (i >= L.length)
	{
		printf("越界！\n");
	}
	next_e = *(p+1);
}

void ListTraverse(struct sqList& L)
{
	for (int i = 0; i<L.length-1; i++)
	{
		printf("%5d", L.elem[i]);
	}
	printf("%5d\n", L.elem[L.length-1]);
}


//在线性表L中查找元素j，如果存在返回下标，如果不存在返回0
int locateElem(struct sqList &L, ElemType j)
{
	int *p = L.elem;		//指向第一个元素
	int i = 1;
	while (i<=L.length && (j != *p))
	{
		++i;
		++p;
	}
	if (i>L.length)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

