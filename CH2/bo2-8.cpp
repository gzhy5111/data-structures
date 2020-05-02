void InitList(struct LNode * &L)
{
	L = NULL;
}

void ClearList(struct LNode * &L)
{
	struct LNode *p = L;			//指向第一个结点
	struct LNode *q;
	while(p->next != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L = NULL;
}

//DestroyList()最后结果和ClearList()一样，都是L = NULL
//所以写成 #define DestroyList ClearList 也可以
void DestroyList(struct LNode * &L)
{
	struct LNode *q;
	while (L->next != NULL)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ListInsert(struct LNode *&L, int pos , ElemType e)
{
	int i = 1;
	struct LNode *p = L;
	if (pos<1)
	{
		printf("ListInsert不合法！\n");
	}

	//新结点
	struct LNode *s = (struct LNode *)malloc(sizeof(LNode));
	s->data = e;
	
	//表头插入元素
	if (pos == 1)			//在表头之前插入元素
	{
		L = s;
		L->next = NULL;
	}
	else
	{
		while (p != NULL && i<pos-1)		//将p定位到pos前面的结点
		{
			p = p->next;
			i++;
		}
		s->next = p->next;
		p->next = s;
	}
}

void ListTraverse(struct LNode * &L)
{
	struct LNode *p = L;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

bool ListEmpty(struct LNode *&L)
{
	if (L == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void GetElem(struct LNode *&L, int pos , ElemType &e)
{
	struct LNode *p = L;
	int i = 1;
	if (i<1)
	{
		printf("越界！\n");
		exit(-1);
	}
	while (i<pos && p)
	{
		i++;
		p = p->next;
	}
	if (i == pos)
	{
		e = p->data;
	}
	else
	{
		printf("未找到！\n");
	}
}

void PriorElem(struct LNode * &L, ElemType cur_e, ElemType &pre_e)
{
	struct LNode *p = L;
	struct LNode *q;
	while (p->next != NULL)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			pre_e = p->data;
		}
		p = q;
	}
}

void NextElem(struct LNode * &L, ElemType cur_e, ElemType &next_e)
{
	struct LNode *p = L;
	while (p->next != NULL)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

void ListDelete(struct LNode * &L, int pos, ElemType &e)
{
	struct LNode *p = L;
	int i = 1;
	if (pos == 1)
	{
		L = p->next;
		e = p->data;
		free(p);
	}
	else
	{
		while (p->next != NULL && i<pos-1)
		{
			i++;
			p = p->next;
		}
	}
	if (p->next == NULL || i>pos-1)
	{
		printf("ListDelete位置非法！\n");
		exit(-1);
	}
	struct LNode *q;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
}

int locateElem(struct LNode * &L, ElemType e1)	//查找线性表中值为e1的元素并返回下标值，如果不存在返回false
{
	struct LNode *p = L;
	int i = 1;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
		if (p->data == e1)
		{
			return i;
		}
	}
	return 0;
}

