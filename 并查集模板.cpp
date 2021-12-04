const int N = 1e5 + 10;
int p[N];	// �洢 n ���ֵ�ĸ��ڵ�

void init(int n)
{
	for(int i = 1; i <= n; i++) p[i] = i;
}

// ���� x �ĸ��ڵ㣬��ѹ�� x -> root ��·��
int find(int x)
{
	if(p[x] != x)	// ���x��㲻�Ǹ����
		p[x] = find(p[x]);  // ��x���ĸ��ڵ�ָ������
	return p[x];
}

// find(a) �� a �ĸ��ڵ�
// find(b) �� b �ĸ��ڵ�
void merge(int a, int b)
{
	p[find(a)] = find(b);   // �� a �ĸ���㸸ָ��ָ�� b �ĸ����
}


int main()
{
	int n, m;
	cin >> n >> m;
	init(n);

	while(m--)
	{
		char op;
		int a, b;
		cin >> op >> a >> b;
		if(op == 'M')
		{
			if(find(a) != find(b)) merge(a, b);
		}
		else 
		{
			if(find(a) == find(b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}
