#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2 * N, INF = 1e9;
int n, m;
int p[N];

struct Edge
{
	int a, b, w;
	bool operator< (const Edge &edge) const
	{
		return w < edge.w;
	}
}edges[M];

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int kruskal()
{
	// 将所有边的权重按照升序排列 
	sort(edges, edges + m);
	// 初始化并查集
	for(int i = 1; i <= n; i++) p[i] = i; 
	
	int res = 0; 	//	最小生成树所有树边的权重之和 
	int cnt = 0;	// 	当前加入加入多少条边 
	for(int i = 0; i < m; i++)	// 从小到大枚举每一条边 
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);	// 寻找两个点的祖宗节点 
		if(a != b)	// 如果两条边所在的集合不是同一个，就进行集合合并 
		{
			p[a] = b;	// 集合合并
			// 更新 res 和 cnt 
			res += w;
			cnt ++;
		}
	}
	// 如果处理的边数量不是 n-1 表示仍然还有点不在集合中，即图是不连通的 
	return cnt == n-1 ? res : INF;
}

int main()
{
	// 输入处理 
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	int t = kruskal();
	if(t == INF) 
		cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
} 
