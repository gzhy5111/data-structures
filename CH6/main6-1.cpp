typedef int TElemType;
TElemType Nil=0; // 设整型以0为空

#include "c1.h"
#include "c6-1.h"
#include "bo6-1.cpp"


void main()
{
	TElemType e;		//SqBiTree[100] e
	SqBiTree T;

	//构造二叉树（只是弄了个全是0的数组，现在还没什么意义）
	InitBiTree(T);

	//创建二叉树（允许从键盘输入值了）
	CreateBiTree(T);

	//判断二叉树是否为空？
	BiTreeEmpty(T);		//返回值为1是空，0代表不是空

	//判断二叉树深度（层数）？
	//BiTreeDepth(T);		//返回值代表数的层数
}