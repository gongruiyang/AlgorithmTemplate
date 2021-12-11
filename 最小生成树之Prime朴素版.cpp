#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 1e9;
int n, m;
int g[N][N];	//  g[i][j] 记录的是 i 到 j 上的边权值 
int dist[N];	// 存储点到 集合 的最短距离 
bool st[N];		// 表示点是否位于集合内 

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	int res = 0;	// 所有边的长度之和 
	for(int i = 0; i < n; i++)	// n 次迭代 
	{
		//	寻找集合外的所有点中距离最短的点放在 t 中 
		int t = -1;
		for(int j = 1 ; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		//	当前距离集合的最近的点的距离是正无穷，说明图是不连通的，即不存在最小生成树 
		if(i && dist[t] == INF) return INF;
		
		// 	只要不是第一个点，就将 t 点与集合之间的最短距离累加入res 
		if(i) res += dist[t];
		//	用 t 来跟新其他点到集合的距离，这一步可能会将dist[t]更新成自环g[t][t]进而导致错误 
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], g[t][j]);
		st[t] = true;	// 加入至集合中 
	}
	return res; 
}

int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);	// 无向图去重边	
	}	
	
	int t = prim();
	
	if(t > INF / 2) cout << "impossible" << endl;
	else cout << t << endl;
	
	return 0;
} 
