#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;

int n, m;
char g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y, int d) 
{
	if(x < 0 || y < 0 || x >= n || y >= m) return 0;
	
	// 镜子折射 
	if (g[x][y] == '/') d ^= 1;
	else d ^= 3;
	
	
	// 寻找折射到的格子 
	int nx = x + dx[d], ny = y + dy[d];
	return dfs(nx, ny, d) + 1;
}
int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i ++) cin >> g[i];
	
	int res = 0;
	for(int i = 0; i < n; i ++)
	{
		res = max(res, dfs(i, 0,   1));	// 入口为第一列
		res = max(res, dfs(i, m-1, 3));	// 入口为最后一列 
	}
	for(int i = 0; i < m; i ++)
	{
		res = max(res, dfs(0,   i, 2));	// 入口为第一行 
		res = max(res, dfs(n-1, i, 0));	// 入口为最后一行 
	}
	
	cout << res << endl;
	
	return 0;
}

