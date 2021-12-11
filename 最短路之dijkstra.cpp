#include <cstring>
#include <iostream>
using namespace std;

const int N = 500 + 10;

int dist[N]; 	// ����ÿ��������һ�������̾��� 
bool st[N];		// ��ʾÿ��������·�Ƿ�ȷ����
int g[N][N];	// ���ڴ洢���б� 
int n, m;

int dijkstra()
{
	// ��ʼ���� ��һ���� �� ÿһ���� ֮��ľ��� 
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; 
	
	// һ���� n ���㣬��Ҫ�ظ� n ��
	for(int i = 0; i < n; i ++)
	{
		int t = -1;	
		// Ѱ�Ҳ��� st �е��Ҿ����һ��������ĵ� t
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[j] < dist[t]))	 
				t = j;
		// ���õ� t ����st�� 
		st[t] = true;
		// �øõ�ȥ�����������е�ľ��룺dist[x] = min(dist[x], dist[t] + Wtx);
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
		g[a][b]= min(g[a][b], c);	// �ر߱�����С�� 
	}
	
	int t = dijkstra();
	cout << t << endl;
	return 0;
} 

 
