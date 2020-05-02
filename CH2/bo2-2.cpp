void InitList(struct LNode * &L)
{
	L = (struct LNode *)malloc(sizeof(struct LNode));
	if (L == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	L->next = NULL;
}

void ListInsert(struct LNode * &L, int pos, ElemType e)
{
	//j和*p都先指向头结点
	int j = 0;
	struct LNode *p = L;

	while (p && j<pos-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>pos-1)
	{
		printf("插入非法！\n");
		exit(-1);
	}
	//创建新结点
	struct LNode *s = (struct LNode *)malloc(sizeof(struct LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void ListTraverse(struct LNode * &L)
{
	struct LNode *p = L->next;			//p指向第一个节点

	//让p移动
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

void GetElem(struct LNode * &L, int pos, ElemType& e)
{
	struct LNode *p = L->next;	//指向第一个结点
	int j = 1;
	while (p !=NULL && j<pos)
	{
		p = p->next;		//让p随着j跳转到第x个结点
		j++;
	}
	e = p->data;
}

bool ListEmpty(struct LNode * &L)
{
	if (L->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void DestoryList(struct LNode * &L)
{
	struct LNode *q;
	while (L != NULL)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ClearList(struct LNode * &L)
{
	struct LNode *p;
	struct LNode *q;
	p = L->next;		//p先指向第一个结点
	while (p != NULL)
	{
		q = p->next;	//q指向p的下一个结点
		free(p);		
		p = q;			//p往后挪
	}
	L->next = NULL;		//头结点指向NULL（回到Init后的状态）
}

void PriorElem(struct LNode * &L, ElemType cur_e, ElemType &pre_e)
{
	struct LNode *p = L->next;		//先指向第一个结点
	struct LNode *q = p->next;		//q指向p下一个结点
	while (p->next != NULL)
	{
		q = p->next;
		if (q->data == cur_e)
		{
			pre_e = p->data;
		}
		p = q;	//p后移
	}
}

void NextElem(struct LNode * &L, ElemType cur_e, ElemType &next_e)
{
	struct LNode *p = L->next;
	while (p->next != NULL)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

int ListLength(struct LNode * &L)
{
	int i = 0;
	struct LNode *p = L->next;
	while (p != NULL)
	{
		i++;
		p =p->next;
	}
	return i;
}

void ListDelete(struct LNode * &L, int pos, ElemType &e)
{
	int i = 0;
	struct LNode *p = L;
	while (p->next && i<pos-1)
	{
		p = p->next;
		i++;
	}
	if (!p->next || i>pos-1)
	{
		printf("delete越界！\n");
		exit(-1);
	}
	struct LNode *q = p->next;	//将被删除的结点指针保留起来，以便于后面的free
	p->next = q->next;
	e = q->data;
	free(q);
}

int locateElem(struct LNode * &L, ElemType e)
{
	int i = 0;						
	struct LNode *p = L->next;	//p指针指向第一个结点
	while (p != NULL)
	{
		i++;
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
	}
	return 0;
}