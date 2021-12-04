
const int N = 8;
int n;
int path[N];
bool flag[N];
void dfs(int u)
{
	// ���һ������
	if (n == u)
	{
		for (int i = 0; i < n; i++)
			cout << path[i] << ' ';
		cout << endl;
		return;
	}
	// ö�ٵ� u λ������ܵ�����
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])	// ����ǰ����δ��ʹ��
		{
			path[u] = i;
			flag[i] = true;
			dfs(u + 1);	// ö����һλ
			flag[i] = false;	// �ָ��ֳ�
		}
	}
}

int main()
{
	while (cin >> n)
	{
		dfs(0);
	}

	return 0;
}
