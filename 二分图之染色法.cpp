#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];	// 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int c)
{
	color[u] = c;	// �Ե� u ������ɫ���� 
	for(int i = h[u]; i != -1; i = ne[i])	// ������ u ���ڽӱ� 
	{
		int j = e[i];
		// �жϵ� j �Ƿ���ɫ 
		if(!color[j])
		{
			// DFS������ɫ 
			bool flag = dfs(j, 3 - c);
			if(!flag) return false;
		}
		else if(color[j] == c) // ����ì�ܣ�һ�����ϵ���������ɫһ�� 
			return false;
	}
	return true;
}

int main()
{
	cin >> n >> m;	
	memset(h, -1, sizeof h);
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);	// ����� 
	}
	
	bool flag = true;
	for(int i = 1; i <= n; i++)	// �������е������ɫ 
	{
		if(!color[i])	// �жϵ�ǰ���Ƿ��Ѿ���ɫ 
		{
			flag = dfs(i, 1);
			if(!flag) break;
		}
	}
	
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
} 
