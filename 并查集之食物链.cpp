const int N = 5e5 + 10;
int p[N], d[N];

void init(int n)
{
	for(int i = 1; i <= n; i++) p[i] = i;
}

int find(int x)
{
	if(p[x] != x)
	{
		int t = find(p[x]);
		// 对路径上的权值进行累加求和，为当前节点至根结点的长度
		d[x] += d[p[x]];    
		p[x] = t;
	}
	return p[x];
}

int main()
{
	int n, m;
	cin >> n >> m;

	init(n);

	int res = 0;
	while(m --)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if(x > n || y > n) 
			res++;
		else
		{
			int px = find(x), py = find(y); // 寻找 x 和 y 的根结点
			if(t == 1) // x 和 y 同类 ->  (d[x] - d[y]) % 3 == 0
			{
				if(px == py && (d[x] - d[y]) % 3) // x 和 y 根结点相同 且 不同类
					res++;
				else if(px != py) //  x 和 y 不在同一个集合，且 x 和 y 是同类
				{
					// 让 x 的根结点指向 y 的根结点
					p[px] = py;
					d[px] = d[y] - d[x]; // ( d[x] + d[find(x)] - d[y] ) % 3 = 0
				}
			}
			else // x 和 y 不同类 且 x 吃 y  -> (d[x] - d[y] - 1) % 3 == 0
			{
				if (px == py && (d[x] - d[y] - 1) % 3) // x 和 y 根结点相同 且 同类
					res++;
				else if (px != py) //  x 和 y 不在同一个集合，且 x 和 y 不是同类，且 x 吃 y
				{
					// 让 x 的根结点指向 y 的根结点
					p[px] = py;
					d[px] = d[y] - d[x] + 1; // ( d[x] + d[find(x)] - d[y] ) % 3 = 1
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}
