
const int N = 1010;
int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;

	// 初始化原矩阵a
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
		cin >> a[i][j];

	// 构造差分矩阵b
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
		insert(i, j, i, j, a[i][j]);
	//b[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];

	// 对差分矩阵b进行+C操作
	while(q--)
	{
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;

		insert(x1, y1, x2, y2, c);
	}

	//  构造前缀和数组
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}

	return 0;
}
