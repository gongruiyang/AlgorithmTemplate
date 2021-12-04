
const int N = 100010;
int m, n;
int a[N],b[N];

int main()
{
	cin >> n >> m;

	// 读取数据
	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);

	// 构造差分数组
	for(int i = 1; i <= n; i++) b[i] = a[i] - a[i-1];

	// 对差分数组进行插入操作
	while(m--)
	{
		int le, ri, c;
		cin >> le >> ri >> c;
		b[le] += c;
		b[ri+1] -= c;
	}

	// 根据 修改过后的差分数组b 计算 新的前缀和数组a
	for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i];

	for(int i = 1; i <= n; i++) printf("%d ", a[i]);

	return 0;
}
