#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];	// match[i] = j ���� i ��Ů����j������ 
bool st[N];		// s[i] = false ��ʾ Ů��i δ������ 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
	for(int i = h[x]; i != -1; i = ne[i])	// �� ����x ���ڽӱ���Ѱ���ʺϵ� Ů��
	{
		int j = e[i];	// ȡ��Ů��j 
		if(!st[j])	// �ж� j ���Ƿ��Ѿ��������� 
		{
			s[j] = true;
			if(match[j] == 0 	// j δ��ƥ�� 
			|| find(match[j]))	// j�Ѿ���match[j]ƥ�䣬���ǻ��ܸ�match[j]�ҵ�����ƥ��ĵ㣬�����ͷų�����ǰ�� j �� 
			{
				match[j] = x;	// �� j �� x ����ƥ�� 
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n1 >> n2 >> m;
	
	memset(h, -1, sizeof h);
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	
	int res = 0;	// �洢ƥ��ĵ�Ķ���
	for(int i = 1; i <= n1; i++)	// ����ߵĵ�Ѱ��ƥ��ĵ� 
	{
		memset(st, false, sizeof st);	// ��֤�ڽӱ��е�ÿ��Ů�����ܱ����� 
		if(find(i)) res++;
	} 
	cout << res << endl;
	 
	return 0;
}
