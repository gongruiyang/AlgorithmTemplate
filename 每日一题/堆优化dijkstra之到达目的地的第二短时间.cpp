#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;


typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 4 * N, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], idx;
int distMin[N], distSecMin[N];	// 存放最短路和次短路 
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
{
	// 图的初始化 
	idx = 0;
    memset(distMin   , INF, sizeof distMin);
    memset(distSecMin, INF, sizeof distSecMin);
    memset(h		 , 	-1, sizeof h);
    memset(e		 , 	 0, sizeof e);
    memset(ne		 , 	 0, sizeof ne);

    // 建立无向图 
    for(auto e : edges)
    {
    	int a = e[0], b = e[1];
    	add(a, b), add(b, a);
	}
	
	// 堆优化版本Dijkstra 
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1}); // <step, 点序号>
	distMin[1] = 0;
	while(!heap.empty())
	{
		// 取出堆顶元素 
		auto t = heap.top();
		int step   = t.first;
		int vertex = t.second;
		heap.pop();
		
		// 遍历 点vertex 的领接表 
		for(int i = h[vertex]; i != -1; i = ne[i])
		{
			int j = e[i];
			// step / change 若为偶数则为绿灯，若为奇数则为红灯 
			int a = step / change, b = step % change;
			int wait = a % 2 == 0 ? 0 : change - b;
			// 红绿灯时间wait + 路径时间time + 走到当前点所需的长度step 
			int dist = step + wait + time;	
			
			if(distMin[j] > dist)	// 发现一个最短距离 
			{
				distSecMin[j] = distMin[j];
				distMin[j] 	  = dist;
				heap.push({distMin[j],    j});
				heap.push({distSecMin[j], j});
			}
			else if(distMin[j] < dist && distSecMin[j] > dist) // 发现一个次短距离
			{
				distSecMin[j] = dist;
				heap.push({distSecMin[j], j});
			} 
		}
	}
	return distSecMin[n];
}
int main()
{
	int n = 5, time = 3, change = 5;
	vector<vector<int>> edges;
	edges.push_back({1, 2});
	edges.push_back({1, 3});
	edges.push_back({1, 4});
	edges.push_back({3, 4});
	edges.push_back({4, 5});
	
	cout << secondMinimum(n, edges, time, change) << endl;
	
	return 0;
}

