#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;


typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 4 * N, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], idx;
int distMin[N], distSecMin[N];	// ������·�ʹζ�· 
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
{
	// ͼ�ĳ�ʼ�� 
	idx = 0;
    memset(distMin   , INF, sizeof distMin);
    memset(distSecMin, INF, sizeof distSecMin);
    memset(h		 , 	-1, sizeof h);
    memset(e		 , 	 0, sizeof e);
    memset(ne		 , 	 0, sizeof ne);

    // ��������ͼ 
    for(auto e : edges)
    {
    	int a = e[0], b = e[1];
    	add(a, b), add(b, a);
	}
	
	// ���Ż��汾Dijkstra 
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1}); // <step, �����>
	distMin[1] = 0;
	while(!heap.empty())
	{
		// ȡ���Ѷ�Ԫ�� 
		auto t = heap.top();
		int step   = t.first;
		int vertex = t.second;
		heap.pop();
		
		// ���� ��vertex ����ӱ� 
		for(int i = h[vertex]; i != -1; i = ne[i])
		{
			int j = e[i];
			// step / change ��Ϊż����Ϊ�̵ƣ���Ϊ������Ϊ��� 
			int a = step / change, b = step % change;
			int wait = a % 2 == 0 ? 0 : change - b;
			// ���̵�ʱ��wait + ·��ʱ��time + �ߵ���ǰ������ĳ���step 
			int dist = step + wait + time;	
			
			if(distMin[j] > dist)	// ����һ����̾��� 
			{
				distSecMin[j] = distMin[j];
				distMin[j] 	  = dist;
				heap.push({distMin[j],    j});
				heap.push({distSecMin[j], j});
			}
			else if(distMin[j] < dist && distSecMin[j] > dist) // ����һ���ζ̾���
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

