#include <cstring>
#include <iostream>
using namespace std;

const int N = 500 + 10;

int dist[N]; 	// 保存每个点距离第一个点的最短距离 
bool st[N];		// 表示每个点的最短路是否确定了
int g[N][N];	// 用于存储所有边 
int n, m;

int dijkstra()
{
	// 初始化从 第一个点 到 每一个点 之间的距离 
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; 
	
	// 一共有 n 个点，需要重复 n 次
	for(int i = 0; i < n; i ++)
	{
		int t = -1;	
		// 寻找不在 st 中的且距离第一个点最近的点 t
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[j] < dist[t]))	 
				t = j;
		// 将该点 t 放入st中 
		st[t] = true;
		// 用该点去跟新其他所有点的距离：dist[x] = min(dist[x], dist[t] + Wtx);
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	} 
	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	
	while(m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b]= min(g[a][b], c);	// 重边保存最小的 
	}
	
	int t = dijkstra();
	cout << t << endl;
	return 0;
} 

 
