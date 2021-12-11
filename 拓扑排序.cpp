#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int m,n;
const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int d[N];	// ��¼ÿ�������� 
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
	// ���������Ϊ0�ĵ���� 
	for(int i = 1; i <= n; i++)
		if(d[i] == 0) q.push(i);
	int count = q.size();	// ����ͳ���������е���� 
	while(q.size())
	{
		int t = q.front();
		q.pop();
		v.push_back(t);
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;	//ɾ�� t->j ֮��ı� 
			if(d[j] == 0)	// �� j �����Ϊ 0 
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
