typedef int TElemType;
TElemType Nil=0; // 设整型以0为空

#include "c1.h"
#include "c6-1.h"
#include "bo6-1.cpp"


void main()
{
	
	SqBiTree T;

	//构造二叉树（只是弄了个全是0的数组，现在还没什么意义）
	InitBiTree(T);

	//创建二叉树（允许从键盘输入值了）
	CreateBiTree(T);

	//判断二叉树是否为空
	int empty = 0;
	if (BiTreeEmpty(T))
	{
		empty = 1;
	}
	else 
	{
		empty = 0;
	}
	printf("建立二叉树后，树空否？（1空，0不空)：%d\n", empty);	//返回值为1是空，0代表不是空

	//判断二叉树深度（层数）
	printf("树的深度：%d\n", BiTreeDepth(T));		//返回值代表数的层数

	// 二叉树的根
	TElemType e;		//SqBiTree[100] e
	Root(T, e);
	printf("树的根是：%d\n", e);

	// 层序遍历二叉树（就是遍历数组）
	printf("层序遍历二叉树：");
	LevelOrderTraverse(T);

	// 中序遍历二叉树（左根右）：使用递归实现
	printf("中序遍历二叉树：");
	InOrderTraverse(T);

	// 后序遍历二叉树（左右根）
	printf("后序遍历二叉树：");
	PostOrderTraverse(T);


	// 修改结点，输入待修改结点的层号和 本层序号
	// 1. 先记录要修改结点的层号和本层序号
	position p;
	printf("请输入想修改的结点的层号（1开始）的本层序号（1开始）,以空格区分开");
	scanf("%d %d", &p.level, &p.order);
	//printf("%d, %d\n", p.level, p.order);

	// 2. 获取原值，录入新值
	// Value是获取值的函数，第二个参数是结点位置结构体
	printf("待修改结点的原值为：%d, 请输入新值：", Value(T, p));
	int newValue;
	scanf("%d", &newValue);
	// 3. Assign函数参数：树, 修改结点位置结构体, 修改后的值
	Assign(T, p, newValue);
	

	// 先序遍历二叉树（根左右）
	printf("先序遍历二叉树：");
	PreOrderTraverse(T);

	// 求双亲、孩子和兄弟
	printf("请输入你想求的结点的值，以求它的双亲、孩子和兄弟的值：");
	scanf("%d", &e);
	printf("结点为%d的双亲为%d， 左右孩子分别为：%d %d， 左右兄弟分别为：%d %d\n", e, Parent(T, e), LeftChild(T, e), RightChild(T, e), LeftSibling(T, e), RightSibling(T, e));

	// 新建树，后续会让子树插入到树中
	SqBiTree S;
	InitBiTree(S);
	CreateBiTree(S);

	// 插入树
	int ParentValue, judge;
	printf("树S插入到树T中，请输入T中树S的双亲结点的值，是要将插入的子树放在左边还是右边呢？（0为左，1为右）：先输入双亲结点的值，再输入左右判断符，以空格区分开");
	scanf("%d %d", &ParentValue, &judge);
	InsertChild(T, S, ParentValue, judge);
	// 输出看下
	printf("层序遍历二叉树：");
	LevelOrderTraverse(T);
}