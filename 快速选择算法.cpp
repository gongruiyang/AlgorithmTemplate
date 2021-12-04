
int quick_select(vector<int>& v, int le, int ri, int k)
{
	// 1. 寻找到了第 k 个数
	if (ri == le)
		return v[le];

	// 2. 在数组中寻找 排序后 应当处于 le 位置的数
	int x = v[le], i = le - 1, j = ri + 1;
	while (i < j)
	{
		do i++; while (v[i] < x);
		do j--; while (v[j] > x);
		if (i < j) 
			swap(v[i], v[j]);
	}

	// 3. 判断：递归访问哪一个分区
	int sl = j - le + 1;
	if (k <= sl)
		return quick_select(v, le, j, k);
	return quick_select(v, j + 1, ri, k - sl);
}
