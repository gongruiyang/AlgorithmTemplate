void quick_sort(vector<int>& v, int le, int ri)
{
	// 递归出口：当分区中只有一个元素
	if (le == ri) return;

	// 确定基准值，保证基准值左边较小，保证基准值右边较大
	int i = le - 1, j = ri + 1, x = v[le + ri >> 1];
	while (i < j)
	{
		do i++; while (v[i] < x);
		do j--; while (v[j] > x);
		if (i < j) 
			swap(v[i], v[j]);
	}

	// 递归将基准两边进行排序
	quick_sort(v, le, j), quick_sort(v, j + 1, ri);
}
