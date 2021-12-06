#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N; // ��¼��С�����ֵ 
int n;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++;
}

// �� u Ϊ���������е������ 
int dfs(int u)
{
	st[u] = true;
	int sum = 1; // ��¼��ǰ�����Ĵ�С
	int res = 0; // ɾ����ǰ��󣬼�¼������ͨ���нڵ�����ֵ 
	// ������ǰ�ڵ���������� 
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			int s = dfs(j); // s ��ʾ�� j Ϊ���������Ĵ�С
			res = max(res, s);
			sum += s;
		} 
	}
	res = max(res, n - sum); 
	ans = min(ans, res);
	return sum; 
}

int main(){
	memset(h, -1, sizeof h);
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		add(a, b), add(b, a);	// ����ͼ 
	}
	dfs(1);
	cout << ans << endl;
	return 0;
} 
