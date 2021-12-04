
int quick_select(vector<int>& v, int le, int ri, int k)
{
	// 1. Ѱ�ҵ��˵� k ����
	if (ri == le)
		return v[le];

	// 2. ��������Ѱ�� ����� Ӧ������ le λ�õ���
	int x = v[le], i = le - 1, j = ri + 1;
	while (i < j)
	{
		do i++; while (v[i] < x);
		do j--; while (v[j] > x);
		if (i < j) 
			swap(v[i], v[j]);
	}

	// 3. �жϣ��ݹ������һ������
	int sl = j - le + 1;
	if (k <= sl)
		return quick_select(v, le, j, k);
	return quick_select(v, j + 1, ri, k - sl);
}
