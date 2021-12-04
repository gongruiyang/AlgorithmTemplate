
const int N = 1010;
int m, n, q;
int a[N][N], s[N][N];

int main()
{
	cin >> n >> m >> q;

	// 初始化原数组a
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
		cin >> a[i][j];

	// 构造二维前缀和数组s
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
		s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];

	// 求数组a中子矩阵和
	while(q--)
	{
		// 初始化矩阵坐标
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 求矩阵和
		int S = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
		cout << S << endl;
	}

	return 0;
}
