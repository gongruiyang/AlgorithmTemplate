
const int N = 3e5 + 10;
int n, m;
int a[N], s[N];

typedef pair<int, int> PII;
vector<int> alls;
vector<PII> add, query;

int find(int x)
{
	int le = 0, ri = alls.size()-1;
	while(le < ri)
	{
		int mid = le + ri >> 1;
		if(alls[mid] >= x)  ri = mid;
		else le = mid + 1;
	}
	return le + 1;
}

int main()
{
	cin >> n >> m;

	// 读入 n 个操作，同时将操作的下标读入到 离散数组alls 中
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x, c });

		alls.push_back(x);
	}

	// 读入 m 个询问，同时将待查询的下标读入到 离散数组alls 中
	for (int i = 0; i < m; i++)
	{
		int le, ri;
		cin >> le >> ri;
		query.push_back({ le, ri });

		alls.push_back(le);
		alls.push_back(ri);
	}

	// 对离散数组进行排序和去重
	sort(alls.begin(), alls.end()); // 排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end()); //去重

	// 将插入的值插入至数组a中
	for (auto e : add)
	{
		int _x = find(e.first);  //获取 x 位于 离散数组alls 中的下标 _x
		a[_x] += e.second;  // 构造操作数组
	}

	// 构造前缀和数组
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	// 处理询问
	for (auto e : query)
	{
		int le = find(e.first), ri = find(e.second);
		cout << s[ri] - s[le - 1] << endl;
	}

	return 0;
}
