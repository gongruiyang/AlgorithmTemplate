#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> 
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
int cnt[N];	
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa()
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		q.push(i);
		st[i] = true;
	}
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;	
				if(cnt[j] >= n) return true;
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
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
	
	if(spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
 } 
