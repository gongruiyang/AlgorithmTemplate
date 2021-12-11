#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1.5e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m; 
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	// <���룬�����> 
	priority_queue< PII, vector<PII>, greater<PII> > heap;
	heap.push({0, 1});
	while(heap.size())
	{
		// ȡ��������С�ĵ� 
		auto t = heap.top();
		heap.pop();
		int distance = t.first;
		int vertex = t.second;
		
		// �ж��Ƿ�Ϊ����� 
		if(st[vertex]) continue;
		
		// ���ĵ�����Ϊ��ȷ�����·�� 
		st[vertex] = true;
		// �øõ�ȥ�����������б� 
		for(int i = h[vertex]; i != -1; i = ne[i])
		{
			int j = e[i]; 
			if(dist[j] > dist[vertex] + w[i])
			{
				dist[j] = dist[vertex] + w[i];
				heap.push({dist[j], j});	// ���ܻ��������Ĳ��� 
			}
		}
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int ans = dijkstra();
	cout << ans << endl;
	
	return 0;
}
