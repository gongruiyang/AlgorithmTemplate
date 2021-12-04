void quick_sort(vector<int>& v, int le, int ri)
{
	// �ݹ���ڣ���������ֻ��һ��Ԫ��
	if (le == ri) return;

	// ȷ����׼ֵ����֤��׼ֵ��߽�С����֤��׼ֵ�ұ߽ϴ�
	int i = le - 1, j = ri + 1, x = v[le + ri >> 1];
	while (i < j)
	{
		do i++; while (v[i] < x);
		do j--; while (v[j] > x);
		if (i < j) 
			swap(v[i], v[j]);
	}

	// �ݹ齫��׼���߽�������
	quick_sort(v, le, j), quick_sort(v, j + 1, ri);
}
