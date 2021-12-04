const int N = 1e5 + 10;
const int M = 31 * N;   // 31 * 1e5 -> 一个数有31位 一共有1e5个数

int son[M][2];  //一共有M个结点 一个结点有 0 和 1 两个结点
int idx = 1;

// 对于插入的x，在字典树中构建该路径
void insert(int x)
{
	int p = 0;
	for(int i = 30; i >= 0; i--)
	{
		int u = (x >> i) & 1;
		if(!son[p][u]) son[p][u] = idx++;
		p = son[p][u];
	}
}

// 求与x异或的最大值
int search(int x)
{
	int p = 0, res = 0;
	for(int i = 30; ~i; i--)
	{
		int u = (x >> i) & 1;
		if(son[p][!u])  // 寻找 x 的第 i 位所在节点的兄弟节点是否存在
		{
			res += 1 << i;  // 第i位符号不同，加上该位产生的值
			p = son[p][!u];
		}
		else p = son[p][u]; // 若第i位只有相同的结点，则不会产生数值
	}
	return res;
}

int main()
{
	int n, a[N];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		insert(a[i]);   // 构建Tri树
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, search(a[i]));

	cout << res << endl;

	return 0;
}
