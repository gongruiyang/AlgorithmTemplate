#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 1e9;
int n, m;
int g[N][N];	//  g[i][j] ��¼���� i �� j �ϵı�Ȩֵ 
int dist[N];	// �洢�㵽 ���� ����̾��� 
bool st[N];		// ��ʾ���Ƿ�λ�ڼ����� 

int prim()
{
	memset(dist, 0x3f, sizeof dist);
	int res = 0;	// ���бߵĳ���֮�� 
	for(int i = 0; i < n; i++)	// n �ε��� 
	{
		//	Ѱ�Ҽ���������е��о�����̵ĵ���� t �� 
		int t = -1;
		for(int j = 1 ; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		//	��ǰ���뼯�ϵ�����ĵ�ľ����������˵��ͼ�ǲ���ͨ�ģ�����������С������ 
		if(i && dist[t] == INF) return INF;
		
		// 	ֻҪ���ǵ�һ���㣬�ͽ� t ���뼯��֮�����̾����ۼ���res 
		if(i) res += dist[t];
		//	�� t �����������㵽���ϵľ��룬��һ�����ܻὫdist[t]���³��Ի�g[t][t]�������´��� 
		for(int j = 1; j <= n; j++)
			dist[j] = min(dist[j], g[t][j]);
		st[t] = true;	// ������������ 
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
		g[a][b] = g[b][a] = min(g[a][b], c);	// ����ͼȥ�ر�	
	}	
	
	int t = prim();
	
	if(t > INF / 2) cout << "impossible" << endl;
	else cout << t << endl;
	
	return 0;
} 
