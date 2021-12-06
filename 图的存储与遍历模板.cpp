#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 
using namespace std;

const int N = 1e5 + 10;
const int M = N * 2;

// 构建图(邻接表)： N 个单链表 
int h[N];	// N个链表的链表头 
int e[N]; 	// 存储每个结点的值 
int ne[M];	// next指针是多少 
int idx;// 此时 e 中第一个可以存储 value 的索引下标，idx之前的下标都被使用了 	
// 搜索图：DFS / BFS 
bool st[N];	//表示哪些点已经被遍历过了 
queue<int> q; // 用于BFS 
// 插入一条 a->b 的边：即在以 a 为头结点的链表中插入 b 
void add(int a, int b)
{
	e[idx] = b;	//创建一个 b 结点 
	// a -> c -> d -> -1
	ne[idx] = h[a];	// h[a] = c ，让 idx 的指针指向 c 
	h[a] = idx;		// 让 a 的指针指向 idx 
	// a -> b -> c -> d -> -1
	idx++;
}

// u: 当前正在遍历的点 
void dfs(int u) 
{
	// 标记 u 被遍历了 
	st[u] = true;
	// 搜索所有出路，即遍历以 u 为头结点的链表 
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
	// N个头结点指向-1 
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
