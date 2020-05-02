void ListInit(struct DuLNode * &L)
{
	//malloc产生的是头节点，不存放有效数据
	L = (struct DuLNode *)malloc(sizeof(struct DuLNode));	//头指针L指向头结点
	if (L == NULL)
	{
		printf("ListInit malloc分配内存失败！\n");
		exit(-1);
	}
	L->prior = L->next = L;
}

int ListLength(DuLNode *&L)
{
	int i = 0;
	struct DuLNode *p = L->next;
	while (p != L)
	{
		i++;
		p = p->next;
	}
	return i;
}

//在双向循环链表中返回第i个元素的地址
DuLNode* GetElemP(struct DuLNode *&L, int pos)
{
	if (pos <0 || pos >ListLength(L))
	{
		printf("GetElemP pos非法\n");
		exit(-1);
	}

	//struct DuLNode *p = L->next;	//指向头结点（非有效结点）
	struct DuLNode *p = L;
	for (int j = 1; j<=pos; j++)	//不确定条件就画一下图
	{
		p = p->next;
	}
	return p;
}

void ListInsert(struct DuLNode *&L, int pos, ElemType e)
{
	if (pos < 1 || pos > ListLength(L)+1)		//eg：表长为2，pos值可以为3，即在尾部插入结点
	{
		printf("ListInsert pos非法");
		exit(-1);
	}

	struct DuLNode *p = GetElemP(L, pos-1);
	if (p == NULL)
	{
		printf("第%d个结点的前驱元素不存在\n", pos);
		exit(-1);
	}

	struct DuLNode *s = (struct DuLNode *)malloc(sizeof(struct DuLNode));
	if (!s)
	{
		printf("ListInsert中的malloc函数分配失败！\n");
		exit(-1);
	}
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;

}

void ListTraverse(struct DuLNode *&L)
{
	struct DuLNode *p = L->next;	//指向首结点（第一个有效元素）
	while (p != L)
	{
		printf("%5d", p->data);
		p =p->next;
	}
	printf("\n");
}

void ListTraverseBack(struct DuLNode *&L)
{
	struct DuLNode *p = L->prior;
	while (p != L)
	{
		printf("%5d", p->data);	
		p = p->prior;
	}
	printf("\n");
}

void ListDelete(struct DuLNode *&L, int pos, ElemType &e)
{
	if (pos<0 || pos>ListLength(L))
	{
		printf("ListDelete pos非法\n");
		exit(-1);
	}

	struct DuLNode *p = GetElemP(L, pos);		//p定位到pos要被删除的元素
	if (!p)
	{
		exit(-1);
	}
	e = p->data;
	//深刻理解下面两句
	p->prior->next = p->next;
	p->next->prior = p->prior;
}

bool ListEmpty(struct DuLNode *&L)
{
	//if (ListLength(L) == 0)
	if (L->prior == L && L->next == L)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClearList(struct DuLNode *&L)
{
	struct DuLNode *q;
	struct DuLNode *p = L->next;	//首结点
	while (p != L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L->prior = L;
}

void GetElem(struct DuLNode *&L, int pos, ElemType &e1)
{
	int j = 1;		//计数器
	struct DuLNode *p = L->next;	//首结点
	while (j<pos && p != L)
	{
		j++;
		p = p->next;
	}
	if (j>pos || p ==L)
	{
		printf("GetElem pos值不合法\n");
		exit(-1);
	}
	e1 = p->data;
}

//找值为val的元素，返回下标
int LocateElem(struct DuLNode *&L, ElemType val)
{
	int i = 0;
	struct DuLNode *p = L->next;
	while (p != L)
	{
		if (val == p->data)
		{
			return i;
		}
		i++;	//用于记录下标值
		p = p->next;
	}
	return i;
}

void PriorElem(struct DuLNode *&L, ElemType cur_e, ElemType &pre_e)
{
	struct DuLNode *p = L->next->next;		//可以直接从第二个有效数据结点开始查找，因为首结点一定没有前序元素
	while (p != L)
	{
		if (p->data == cur_e)
		{
			pre_e = p->prior->data;
		}
		p = p->next;
	}
}

void NextElem(struct DuLNode *&L, ElemType cur_e, ElemType &next_e)
{
	struct DuLNode *p = L->next;
	while (p != L)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
		}
		p = p->next;
	}
}

void DestroyList(struct DuLNode *&L)
{
	struct DuLNode *q;
	struct DuLNode *p = L->next;	//首结点
	while (p != L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
	L = NULL;
}