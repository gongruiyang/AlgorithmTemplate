const int N = 1e6 + 10;

// a:�洢ԭ����
// q:�������У��洢������ֵ���±�
int a[N], q[N];

int main()
{
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)  
		cin >> a[i];

	// �������У�����
	int head = 0, tail = -1;
	for(int i = 0; i < n; i++)
	{
		// �ж϶�ͷ�Ƿ��Ѿ����ڴ�����
		if(head <= tail && i - k + 1 > q[head])
			head++;

		// �ж϶�βԪ�����ȵ�ǰֵ����ɾ��
		while(head <= tail && a[q[tail]] >= a[i])
			tail--;
		// ����ǰֵ�±���뵥��������
		q[++tail] = i;

		// �������γ�ʱ��ʼ���
		if(i >= k - 1)
			cout << a[q[head]] << " ";
	}

	cout << endl;

	// �������У�����
	head = 0, tail = -1;
	for(int i = 0; i < n; i++)
	{
		// �ж϶�ͷ�Ƿ��Ѿ����ڴ�����
		if(head <= tail && i - k + 1 > q[head])
			head++;

		// �ж϶�βԪ�����ȵ�ǰֵС��ɾ��
		while(head <= tail && a[q[tail]] <= a[i])
			tail--;
		// ����ǰֵ�±���뵥��������
		q[++tail] = i;

		// �������γ�ʱ��ʼ���
		if (i >= k - 1)
			cout << a[q[head]] << " ";
	}
	cout << endl;
	return 0;
}
