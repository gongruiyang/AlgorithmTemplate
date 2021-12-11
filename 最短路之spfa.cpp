#include <iostream>
using namespace std;

int n, m;
const int N = 1e5 + 10;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];	//防止队列中存储重复的点 
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
} 
int spfa()
{
	// 距离初始化 
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	queue<int> q;
	q.push(1);
	st[1] = true;
	
	while(q.size())
	{
		// 取出队头 
		int t = q.front();
		q.pop();
		st[t] = false;
		// 更新所有 t 的出边   
		for(int i = h[t]; i != -1; i = ne[i])	// 遍历 t 的邻接表 
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])	// 队列中不存在 j 时才入队 
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
