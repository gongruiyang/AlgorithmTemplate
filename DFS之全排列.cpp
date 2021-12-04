
const int N = 8;
int n;
int path[N];
bool flag[N];
void dfs(int u)
{
	// 完成一个排列
	if (n == u)
	{
		for (int i = 0; i < n; i++)
			cout << path[i] << ' ';
		cout << endl;
		return;
	}
	// 枚举第 u 位上面可能的数字
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])	// 若当前数字未被使用
		{
			path[u] = i;
			flag[i] = true;
			dfs(u + 1);	// 枚举下一位
			flag[i] = false;	// 恢复现场
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
