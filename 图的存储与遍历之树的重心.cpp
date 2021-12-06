#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N; // 记录最小的最大值 
int n;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++;
}

// 以 u 为根的子树中点的数量 
int dfs(int u)
{
	st[u] = true;
	int sum = 1; // 记录当前子树的大小
	int res = 0; // 删除当前点后，记录所有连通块中节点的最大值 
	// 遍历当前节点的所有子树 
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			int s = dfs(j); // s 表示以 j 为根的子树的大小
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
		add(a, b), add(b, a);	// 无向图 
	}
	dfs(1);
	cout << ans << endl;
	return 0;
} 
