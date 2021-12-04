const int N = 20;
int n;  // 棋盘边长
char map[N][N];// 棋盘
bool col[N];// 列
bool dg[N], udg[N]; // 对角线

void dfs(int u)
{
	// 出现一组解
	if (u == n)
	{
		for (int i = 0; i < n; i++)
			cout << map[i] << endl;
		cout << endl;
		return;
	}
	// 
	for (int i = 0; i < n; i++)
	{
		if (!col[i] && !dg[u + i] && !udg[i - u + n])
		{
			map[u][i] = 'Q';
			col[i] = dg[u + i] = udg[i - u + n] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[i - u + n] = false;
			map[u][i] = '.';
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = '.';
		}
	}
	dfs(0);
	return 0;
}
