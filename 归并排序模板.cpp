
void merge_sort(vector<int>& v, int le, int ri, vector<int>& tmp)
{
	//1. 当前区间只有一个数，就开始排序了
	if(le >= ri)    
		return ;

	// 2. 取中点
	int mid = le + ri >> 1;     

	// 3. 递归中点两边
	merge_sort(v, le, mid, tmp), merge_sort(v, mid+1, ri, tmp);   

	// 4. 使用双指针对 [le, mid] 和 [mid+1, ri] 中的元素排序至 临时数组 中
	int k = 0, i = le, j = mid + 1;		
	while(i <= mid && j <= ri)
	{
		if (v[i] <= v[j]) tmp[k++] = v[i++];
		else tmp[k++] = v[j++];
	}
	while (i <= mid)
	{
		tmp[k++] = v[i++];
	}
	while (j <= ri)
	{
		tmp[k++] = v[j++];
	}

	// 5. 将排好序的[le, ri]赋值回原数组中
	for (i = le, k = 0; i <= ri; i++, k++)
		v[i] = tmp[k];
}
