//栈的顺序表示及实现

void InitStack(struct SqStack &S)
{
	S.base = (SElemType *)malloc(20*sizeof(SElemType));
	if (S.base == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	S.top = S.base;
	S.stacksize = 20;
}

void Push(struct SqStack &S, SElemType e)
{
	//先赋值给top原来指向的位置空间，再将top指针+1
	*S.top = e;
	S.top = S.top+1;
}

void StackTraverse(struct SqStack &S)
{
	SElemType* p = S.base;
	while (p != S.top)
	{
		printf("%5d", *p);
		p = p + 1;
	}
	printf("\n");
}

void Pop(struct SqStack &S, SElemType &e)
{
	//先判断栈空，如果栈为空则返回错误
	if (S.top == S.base)
	{
		printf("栈为空，不能删除元素\n");
		exit(-1);
	}
	e = *--S.top;	//先后退一个单位，再返回
}

bool StackEmpty(struct SqStack &S)
{
	if (S.top == S.base)
	{
		return 1;	//栈为空
	}
	else
	{
		return 0;	//不空
	}
}

void GetTop(struct SqStack &S, SElemType &e)
{
	if (S.top == S.base)
	{
		printf("栈是空的\n");
		exit(-1);
	}

	S.top = S.top - 1;
	e = *S.top;
}

int StackLength(struct SqStack &S)
{
		
}