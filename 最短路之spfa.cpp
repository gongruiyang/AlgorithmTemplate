#include <iostream>
using namespace std;

int n, m;
const int N = 1e5 + 10;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];	//��ֹ�����д洢�ظ��ĵ� 
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
} 
int spfa()
{
	// �����ʼ�� 
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
	q.push(1);
	st[1] = true;
	
	while(q.size())
	{
		// ȡ����ͷ 
		int t = q.front();
		q.pop();
		st[t] = false;
		// �������� t �ĳ���   
		for(int i = h[t]; i != -1; i = ne[i])	// ���� t ���ڽӱ� 
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])	// �����в����� j ʱ����� 
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return dist[n];
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	
	int t = spfa();
	
	if(t == -1) cout << "impossible" << endl;
	else cout << t << endl;
	
	return 0;
} 
