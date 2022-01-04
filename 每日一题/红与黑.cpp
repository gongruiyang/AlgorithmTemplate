#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
/*
	Flood Fill \ DFS \ BFS 
*/

#if 0 // DFS

const int N = 25;
int n, m;
char g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y)
{
	int res = 1;
	g[x][y] = '#';
	for(int i = 0; i < 4; i ++)
	{
		int a = x + dx[i], b = y + dy[i];
		if(a >= 0 && b >= 0 && a < n && b < m && g[a][b] == '.')
			res += dfs(a, b);
	}
	return res;
}

int main()
{
	while(cin >> m >> n, n || m)
	{
		// 输入地图 找到起始位置[x, y] 
		for(int i = 0; i < n; i++) cin >> g[i];
		int x, y;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(g[i][j] == '@')
					x = i, y = j;
		cout << dfs(x, y) << endl;
	}

	return 0;
}

#endif

#if 0 // BFS

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 25;
int n, m;
char g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs(int sx, int sy)
{
	queue<PII> q;
	q.push({sx, sy});
	g[sx][sy] = '#';
	int res = 0;
	
	while(!q.empty())
	{
		PII t = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') continue;
			g[x][y] = '#';
			q.push({x, y});
			res++; 
		}
	}
	
	return res;
}

int main()
{
	while(cin >> m >> n, n || m)
	{
		// 输入地图 找到起始位置[x, y] 
		for(int i = 0; i < n; i++) cin >> g[i];
		int x, y;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(g[i][j] == '@')
					x = i, y = j;
		cout << bfs(x, y) << endl;
	}

	return 0;
}

#endif
