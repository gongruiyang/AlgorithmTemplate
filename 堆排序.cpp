const int N = 1e5 + 10;
int h[N], cnt;
void down(int x)
{
	int t = x, le =  x * 2, ri = x * 2 + 1;
	// Ѱ����С���ӽڵ���±�
	if(le <= cnt && h[le] < h[t]) t = le;
	if(ri <= cnt && h[ri] < h[t]) t = ri;
	// �� x��� �� t�ӽڵ� ���н���
	if(t != x)
	{
		swap(h[x], h[t]);
		down(t);
	}
}
// o(n)����
void make_heap()
{
	for(int i = cnt/2; i; i--) 
		down(i);
}
// ɾ���Ѷ�Ԫ��
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
