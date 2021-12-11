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
	// �����бߵ�Ȩ�ذ����������� 
	sort(edges, edges + m);
	// ��ʼ�����鼯
	for(int i = 1; i <= n; i++) p[i] = i; 
	
	int res = 0; 	//	��С�������������ߵ�Ȩ��֮�� 
	int cnt = 0;	// 	��ǰ�������������� 
	for(int i = 0; i < m; i++)	// ��С����ö��ÿһ���� 
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);	// Ѱ������������ڽڵ� 
		if(a != b)	// ������������ڵļ��ϲ���ͬһ�����ͽ��м��Ϻϲ� 
		{
			p[a] = b;	// ���Ϻϲ�
			// ���� res �� cnt 
			res += w;
			cnt ++;
		}
	}
	// �������ı��������� n-1 ��ʾ��Ȼ���е㲻�ڼ����У���ͼ�ǲ���ͨ�� 
	return cnt == n-1 ? res : INF;
}

int main()
{
	// ���봦�� 
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
