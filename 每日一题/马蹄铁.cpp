#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10;
int n, ans;
bool vis[N][N]; // 用来判断格子是否被走过
char g[N][N];   // 存储地图
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// le : 左括号数量  ri : 右括号数量
void dfs(int x, int y, int le, int ri)
{
	if(le != 0 && le == ri)
	{
		ans = max(ans, le);
		return ;
	}
	for(int i = 0; i < 4; i++)	// 搜索四个方向 
	{
		// 获取即将遍历的点坐标 
		int a = x + dx[i], b = y + dy[i]; 
		/* 判断合法性：
			1. 点不能出地图 
			2. 点不能被遍历过 
			3. ri>0说明已经开始放入右括号了，如果再遇到左括号应该忽略当前坐标 
		*/ 
		if(a < 1 || b < 1 || a > n || b > n || vis[a][b] || (ri > 0 && g[a][b] == '(')) continue;	
		
		// DFS + 回溯
		vis[a][b] = 1;
		if(g[a][b] == '(') 	dfs(a, b, le + 1, ri);
		else 				dfs(a, b, le, ri + 1);
		vis[a][b] = 0;
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> g[i] + 1;
		
	// 初始位置必须为左括号
	if(g[1][1] == ')')
	{
		cout << ans << endl;
		return 0;
	}
	
	vis[1][1] = 1;
	dfs(1, 1, 1, 0);
	
	cout << ans * 2 <<endl; 
	return 0;
}

