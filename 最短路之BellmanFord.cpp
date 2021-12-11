#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
const int N = 510, M = 1e4 + 10;
int dist[N], backup[N];
struct Edge
{
	int a, b, w;
}edges[M];
int bellman_ford()
{
	// ��ʼ������ 
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;  
	for(int i = 0; i < k; i++)	// ���� k �� 
	{
		memcpy(backup, dist, sizeof dist);
		for(int j = 0; j < m; j++)	// ���ÿ���� 
		{
			auto e = edges[j];
			dist[e.b] = min(dist[e.b], backup[e.a] + e.w);	// �ɳڲ��� 
		}
	}
	return dist[n];
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = {a, b, c};
	}
	
	int t = bellman_ford();
	if(t  > 0x3f3f3f3f / 2)
		cout << "impossible" << endl;
	else cout << t << endl;
	
	return 0;
 } 
