const int N = 1e5 + 10;
int p[N];	// 存储 n 这个值的父节点

void init(int n)
{
	for(int i = 1; i <= n; i++) p[i] = i;
}

// 返回 x 的根节点，并压缩 x -> root 的路径
int find(int x)
{
	if(p[x] != x)	// 如果x结点不是根结点
		p[x] = find(p[x]);  // 让x结点的父节点指向根结点
	return p[x];
}

// find(a) 是 a 的根节点
// find(b) 是 b 的根节点
void merge(int a, int b)
{
	p[find(a)] = find(b);   // 让 a 的根结点父指针指向 b 的根结点
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
