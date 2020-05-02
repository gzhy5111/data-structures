//栈的顺序表示及实现

struct SqStack
{
	SElemType* base;	//栈底指针
	SElemType* top;		//栈顶指针
	int stacksize;		//栈容量大小
};