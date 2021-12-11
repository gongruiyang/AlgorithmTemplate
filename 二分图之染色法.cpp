#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];	// 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int c)
{
	color[u] = c;	// 对点 u 进行着色操作 
	for(int i = h[u]; i != -1; i = ne[i])	// 遍历点 u 的邻接表 
	{
		int j = e[i];
		// 判断点 j 是否着色 
		if(!color[j])
		{
			// DFS向下着色 
			bool flag = dfs(j, 3 - c);
			if(!flag) return false;
		}
		else if(color[j] == c) // 出现矛盾：一条边上的两个点颜色一样 
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;	
	memset(h, -1, sizeof h);
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);	// 无向边 
	}
	
	bool flag = true;
	for(int i = 1; i <= n; i++)	// 遍历所有点进行着色 
	{
		if(!color[i])	// 判断当前点是否已经着色 
		{
			flag = dfs(i, 1);
			if(!flag) break;
		}
	}
	
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
} 
