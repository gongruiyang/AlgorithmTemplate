#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int m,n;
const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int d[N];	// 记录每个点的入度 
queue<int> q;
vector<int> v;
int add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

bool topsort()
{
	// 将所有入度为0的点入队 
	for(int i = 1; i <= n; i++)
		if(d[i] == 0) q.push(i);
	int count = q.size();	// 用于统计拓扑序列点个数 
	while(q.size())
	{
		int t = q.front();
		q.pop();
		v.push_back(t);
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;	//删除 t->j 之间的边 
			if(d[j] == 0)	// 若 j 的入度为 0 
			{
				q.push(j);
				count ++;
			}
		}
	}
	return count == n;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b]++;
	}	
	if(topsort())
	{
		for(auto e : v)
			cout << e << " ";
		cout << endl;
	}
	else cout << "-1" << endl;
	
	return 0;
 } 
