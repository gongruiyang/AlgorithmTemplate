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
		// ��·���ϵ�Ȩֵ�����ۼ���ͣ�Ϊ��ǰ�ڵ��������ĳ���
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
			int px = find(x), py = find(y); // Ѱ�� x �� y �ĸ����
			if(t == 1) // x �� y ͬ�� ->  (d[x] - d[y]) % 3 == 0
			{
				if(px == py && (d[x] - d[y]) % 3) // x �� y �������ͬ �� ��ͬ��
					res++;
				else if(px != py) //  x �� y ����ͬһ�����ϣ��� x �� y ��ͬ��
				{
					// �� x �ĸ����ָ�� y �ĸ����
					p[px] = py;
					d[px] = d[y] - d[x]; // ( d[x] + d[find(x)] - d[y] ) % 3 = 0
				}
			}
			else // x �� y ��ͬ�� �� x �� y  -> (d[x] - d[y] - 1) % 3 == 0
			{
				if (px == py && (d[x] - d[y] - 1) % 3) // x �� y �������ͬ �� ͬ��
					res++;
				else if (px != py) //  x �� y ����ͬһ�����ϣ��� x �� y ����ͬ�࣬�� x �� y
				{
					// �� x �ĸ����ָ�� y �ĸ����
					p[px] = py;
					d[px] = d[y] - d[x] + 1; // ( d[x] + d[find(x)] - d[y] ) % 3 = 1
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}
