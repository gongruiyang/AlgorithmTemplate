
void merge_sort(vector<int>& v, int le, int ri, vector<int>& tmp)
{
	//1. ��ǰ����ֻ��һ�������Ϳ�ʼ������
	if(le >= ri)    
		return ;

	// 2. ȡ�е�
	int mid = le + ri >> 1;     

	// 3. �ݹ��е�����
	merge_sort(v, le, mid, tmp), merge_sort(v, mid+1, ri, tmp);   

	// 4. ʹ��˫ָ��� [le, mid] �� [mid+1, ri] �е�Ԫ�������� ��ʱ���� ��
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

	// 5. ���ź����[le, ri]��ֵ��ԭ������
	for (i = le, k = 0; i <= ri; i++, k++)
		v[i] = tmp[k];
}
