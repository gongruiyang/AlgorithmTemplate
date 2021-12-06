#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 
using namespace std;

const int N = 1e5 + 10;
const int M = N * 2;

// ����ͼ(�ڽӱ�)�� N �������� 
int h[N];	// N�����������ͷ 
int e[N]; 	// �洢ÿ������ֵ 
int ne[M];	// nextָ���Ƕ��� 
int idx;// ��ʱ e �е�һ�����Դ洢 value �������±꣬idx֮ǰ���±궼��ʹ���� 	
// ����ͼ��DFS / BFS 
bool st[N];	//��ʾ��Щ���Ѿ����������� 
queue<int> q; // ����BFS 
// ����һ�� a->b �ıߣ������� a Ϊͷ���������в��� b 
void add(int a, int b)
{
	e[idx] = b;	//����һ�� b ��� 
	// a -> c -> d -> -1
	ne[idx] = h[a];	// h[a] = c ���� idx ��ָ��ָ�� c 
	h[a] = idx;		// �� a ��ָ��ָ�� idx 
	// a -> b -> c -> d -> -1
	idx++;
}

// u: ��ǰ���ڱ����ĵ� 
void dfs(int u) 
{
	// ��� u �������� 
	st[u] = true;
	// �������г�·���������� u Ϊͷ�������� 
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			cout << j << endl;
			dfs(j);
		}
	}
}
void bfs(int u)
{
	q.push(u);
	while(!q.empty())
	{
		auto head = q.front();
		q.pop();
		for(int i = h[head]; i != -1; i = ne[i])
		{
			int j = e[i];
			q.push(j);
			cout << j << endl;
		}	
	}
}

int main()
{
	// N��ͷ���ָ��-1 
	memset(h, -1, sizeof h);
	/*
		1 2
		1 7
		1 4
		2 8
		2 5
		4 3
		3 9
		4 6
	*/
	add(1, 2);
	add(1, 7);
	add(1, 4);
	add(2, 8);
	add(2, 5);
	add(4, 3);
	add(3, 9);
	add(4, 6);
	
	dfs(1);
	
	return 0;
}
