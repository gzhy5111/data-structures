//二叉树的顺序存储结构
// 在修改结点的值的时候，通过层号和本层序号的找到，为了方便，我们用结构体括起来
typedef TElemType SqBiTree[100];		// 默认MAX_TREE_SIZE等于100
struct position		//位置
{
	int level, order;		//层数, 本层序号
};