void InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	T = (ElemType *)malloc(3*sizeof(ElemType));
	
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
}

void Get(Triplet T, int pos, ElemType &e)
{
	e = T[pos-1];
}

void Put(Triplet T, int pos, ElemType e)
{
	T[pos-1] = e;
}

bool IsAscending(Triplet T)
{
	if (T[0] <= T[1] && T[1] <= T[2])
	{
		return 1;
	}
}

bool IsDescending(Triplet T)
{
	if (T[0] >= T[1] && T[1] >= T[2])
	{
		return 1;
	}
}

void Max(Triplet T, ElemType &max)
{
	max = T[0]>=T[2]?(T[0]>=T[2]?T[0]:T[2]):(T[1]>=T[2]?T[1]:T[2]);
}

void Min(Triplet T, ElemType& min)
{
	min = T[0]<=T[1]?(T[0]<=T[2]?T[0]:T[2]):(T[1]<=T[2]?T[1]:T[2]);
}

bool Destroy(Triplet T)
{
	free(T);
	T = NULL;
	return 1;
}