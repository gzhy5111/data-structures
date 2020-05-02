void InitBiTree(SqBiTree T)			//构造空的二叉树（就是数组）
{
	int i;
	for (i = 0; i < 100; i++)
	{
		T[i] = 0;
	}
}

void CreateBiTree(SqBiTree T)
{
	printf("请按照完全二叉树的方式输入数值，以创建二叉树（0表示空结点，999表示结束）");
	int i = 0;
	InitBiTree(T);
	while (1)
	{
		scanf("%d", T[i]);			//输入0和其他值都照填进二叉树中（除了999）
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

int BiTreeDepth(SqBiTree T)
{
	
}

