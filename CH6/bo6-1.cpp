// 构造空的二叉树（就是数组）
void InitBiTree(SqBiTree T)			
{
	int i;
	for (i = 0; i < 100; i++)
	{
		T[i] = 0;
	}
}

// 创建二叉树
void CreateBiTree(SqBiTree T)
{
	printf("请按照完全二叉树的方式输入数值，以创建二叉树（0表示空结点，999表示结束）");
	int i = 0;
	InitBiTree(T);
	while (1)
	{
		scanf("%d", &T[i]);			//输入0和其他值都照填进二叉树中（除了999）
		if (T[i] == 999)
		{
			T[i] = 0;			//如果输入的值是999，就改为0代表空结点
			break;
		}
		i++;
	}
}

bool BiTreeEmpty(SqBiTree T)
{
	if (T[0] == 0)				//根节点为0代表树为空
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 返回树的深度
int BiTreeDepth(SqBiTree T)
{
	// 先求最后一个结点的序号
	int i;
	for (i = 100-1; i >= 0; i--)
	{
		// 最后一个有效结点
		if (T[i] != 0)
		{
			break;
		}
	}
	// 现在得到了最后一个有效结点的序号，结点序号是从0开始的
	i = i + 1;
	// 计算深度
	int j = 0;			// j代表树的深度
	do
	{
		j++;
	} while (i >= pow(2, j));
	return j;
}

void Root(SqBiTree T, TElemType &b)
{
	// 树为空，不存在根结点
	if (BiTreeEmpty(T))
	{
		exit(-1);
	}
	else
	{
		b = T[0];
	}
}

// 层序遍历二叉树
void LevelOrderTraverse(SqBiTree T)
{
	for (int i = 0; i < 100; i++)
	{
		if (T[i] != 0)
		{
			printf("%5d", T[i]);
		}
	}
	printf("\n");
}

// 左根右遍历
void InTraverse(SqBiTree T, int i)
{	
	// 递归实现
	if (T[2*i+1] != 0)			// 左子树不为空
	{
		InTraverse(T, 2*i+1);
	}
	printf("%5d", T[i]);			// 根
	if (T[2*i+2] != 0)
	{
		InTraverse(T, 2*i+2);	//右子树不为空
	}
	
}

// 中序遍历二叉树（左根右）
void InOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		// 左根右遍历
		InTraverse(T, 0);
	}
	printf("\n");
}

// 左右根遍历
void PostTravese(SqBiTree T, int i)
{
	if (T[2*i+1] != 0)			// 左子树不为空
	{
		PostTravese(T, 2*i+1);
	}
	if (T[2*i+2] != 0)
	{
		PostTravese(T, 2*i+2);	//右子树不为空
	}
	printf("%5d", T[i]);			// 根
}

// 后序遍历二叉树（左右根）
void PostOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		// 左右根遍历
		PostTravese(T, 0);
	}
	printf("\n");
}

// Value是获取值的函数，第二个参数是结点位置结构体
TElemType Value(SqBiTree T, position p)
{
	return T[int(pow(2, p.level-1) + p.order-2)];
}

// Assign函数参数：树, 修改结点位置结构体, 修改后的值
void Assign(SqBiTree T, position p, TElemType newValue)
{
	int i = (pow(2, p.level-1)) + p.order-2;	// 转换为序号值（从0开始计数）
	// 注意：不能直接赋值，要考虑其有没有父节点问题
	// 情况一：赋值不是“0”，但双亲为空——不符合逻辑
	if (newValue != 0 && T[(i+1)/2-1] == 0)
	{
		printf("情况一出错！\n");
		exit(-1);
	}
	// 情况二：要赋的值为0（说明不想有孩子），要保证孩子不能存在才行
	if (newValue ==0 && (T[i*2+1] || T[i*2+2]))
	{
		printf("情况二出错！\n");
		exit(-1);	
	}
	T[i] = newValue;
}

// 根左右遍历
void PreTravese(SqBiTree T, int i)
{
	printf("%5d", T[i]);		// 根
	if (T[2*i+1] != 0)			// 左子树不为空
	{
		PreTravese(T, 2*i+1);
	}
	if (T[2*i+2] != 0)
	{
		PreTravese(T, 2*i+2);	//右子树不为空
	}
}

// 先序遍历二叉树（根左右）
void PreOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T))
	{
		// 根左右遍历
		PreTravese(T, 0);
	}
	printf("\n");
}

// e是数值，根据数值求双亲结点的值
int Parent(SqBiTree T, TElemType e)
{
	// 空树
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e)
		{
			// 返回双亲结点的值
			return T[(i+1)/2-1];
		}
	}
	// 如果没有找到e则返回0
	return 0;
} 

// 根据值，求左孩子的值
int LeftChild(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e)
		{
			// 返回左孩子的值
			return T[i*2+1];
		}
	}
	// 如果没有找到e则返回0
	return 0;
}

int RightChild(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e)
		{
			// 返回右孩子的值
			return T[i*2+2];
		}
	}
	// 如果没有找到e则返回0
	return 0;
}

// 根据值求左兄弟的值
int LeftSibling(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e && i%2 == 0)
		{
			// 返回左兄弟的值
			// 通过观察可发现，奇数编号的结点只有右兄弟（有且只有一个，堂兄弟不算），偶数编号的结点只有左兄弟（堂兄不算且编号为0的结点例外，它没有兄弟）
			return T[i-1];
		}
	}
	// 如果没有找到e则返回0
	return 0;
}

int RightSibling(SqBiTree T, TElemType e)
{
	if (T[0] == 0)
	{
		return 0;
	}
	for (int i = 0; i < 100; i++) 
	{
		if (T[i] == e && i%2 != 0)
		{
			// 返回右兄弟的值
			// 通过观察可发现，奇数编号的结点只有右兄弟（有且只有一个，堂兄弟不算），偶数编号的结点只有左兄弟（堂兄不算且编号为0的结点例外，它没有兄弟）
			return T[i+1];
		}
	}
	// 如果没有找到e则返回0
	return 0;
}

// 移动树
// 把从q的j结点开始的子树移动至T的i结点开始的子树
void Move(SqBiTree q, int j, SqBiTree T, int i)
{
	// 如果左子树不为空
	if (q[j*2+1] != 0)
	{
		Move(q, j*2+1, T, i*2+1);
	}
	// 如果右子树不为空
	if (T[j*2+2] != 0)
	{
		Move(q, j*2+2, T, i*2+2);
	}
	T[i] = q[j];
	q[j] = 0;
}

// 插入树
void InsertChild(SqBiTree T, SqBiTree C, int ParentValue, int judge)
{
	// 查找值为ParentValue的编号
	int i;			// 变量i存放双亲结点的编号
	for (i = 0; i < pow(2, BiTreeDepth(T))-1; i++)
	{
		if (T[i] == ParentValue)
		{
			break;
		}
	}
	// 接下来需要判断双亲结点本来的左孩子和右孩子是否存在
	// 存在的话，如果位置不合适，还需要调换（左右调换）
	int childIndex = (2*i+1) + judge;		// 很巧妙，左孩子是2*i+1，右孩子是2*i+2，正好通过Judge来凑数
	//如果孩子占了位置，则需要将它左右调换
	if (T[childIndex] != 0)
	{
		// 把从T的childIndex开始的结点的子树（占位置的树）移动到从childIndex结点的右子树开始的子树
		Move(T, childIndex, T, childIndex*2+2);
	}
	// 把之前碍事的是子树移走后，现在就可以插入新树了
	// 第二个参数0表示“新子树全部插入”
	Move(C, 0, T, childIndex);
}