//栈的顺序表示及实现
#include "c1.h"
typedef int SElemType;
#include "c3-1.h"
#include "bo3-1.cpp"


void main()
{
	struct SqStack	S;
	//Init
	InitStack(S);

	//Push
	int j = 1;
	Push(S, j);		//对哪个栈操作,插入什么值

	//批量Push（新增）
	int k;
	for (k = 2; k <= 12; k++)
	{
		Push(S, k);
	}

	//遍历
	StackTraverse(S);


	//Pop(删除，弹出)
	int e;	//弹出栈顶元素
	Pop(S, e);
	printf("被删除的栈顶元素是：%d\n", e);

	//判空
	if (StackEmpty(S))
	{
		printf("栈空\n");
	}
	else
	{
		printf("栈不为空\n");
	}

	//获取栈顶元素
	GetTop(S, e);
	printf("栈顶元素是：%d\n", e);

	//栈长度
	StackLength(S);		//通过返回值取得长度
}