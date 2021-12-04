const int N = 1e5 + 10;
int h[N], cnt;
void down(int x)
{
	int t = x, le =  x * 2, ri = x * 2 + 1;
	// 寻找最小的子节点的下标
	if(le <= cnt && h[le] < h[t]) t = le;
	if(ri <= cnt && h[ri] < h[t]) t = ri;
	// 将 x结点 与 t子节点 进行交换
	if(t != x)
	{
		swap(h[x], h[t]);
		down(t);
	}
}
// o(n)建堆
void make_heap()
{
	for(int i = cnt/2; i; i--) 
		down(i);
}
// 删除堆顶元素
void pop()
{
	h[1] = h[cnt--];
	down(1);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> h[i];
	cnt = n;

	make_heap();

	while(m--)
	{
		cout << h[1] << " ";
		pop();
	}

	return 0;
}
