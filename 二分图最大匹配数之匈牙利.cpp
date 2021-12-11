#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];	// match[i] = j 其中 i 是女生，j是男生 
bool st[N];		// s[i] = false 表示 女生i 未被分配 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
	for(int i = h[x]; i != -1; i = ne[i])	// 在 男生x 的邻接表中寻找适合的 女生
	{
		int j = e[i];	// 取出女生j 
		if(!st[j])	// 判断 j 点是否已经被分配了 
		{
			s[j] = true;
			if(match[j] == 0 	// j 未被匹配 
			|| find(match[j]))	// j已经被match[j]匹配，但是还能给match[j]找到其他匹配的点，进而释放出来当前的 j 点 
			{
				match[j] = x;	// 让 j 与 x 进行匹配 
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
	
	int res = 0;	// 存储匹配的点的对数
	for(int i = 1; i <= n1; i++)	// 给左边的点寻找匹配的点 
	{
		memset(st, false, sizeof st);	// 保证邻接表中的每个女生都能遍历到 
		if(find(i)) res++;
	} 
	cout << res << endl;
	 
	return 0;
}
