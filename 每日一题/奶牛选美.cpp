#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
	Flood Fill \ DFS \ BFS \ 枚举 
*/ 
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 55;
int n, m;
char g[N][N];	// 存地图 
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};	// 控制搜索方向 

void bfs(int sx, int sy, vector<PII>& v)
{
	queue<PII> q;
	/* 
	初始化状态：
		1. 将该点[sx, sy]放入队列中 
		2. 将该点[sx, sy]设置为已经被遍历 X-> . 
		3. 将该点[sx, sy]放入v中 
	*/ 
	g[sx][sy] = '.';
	q.push({sx, sy});
	v.push_back({sx, sy});
	// 使用队列进行 BFS 
	while(!q.empty())
	{
		PII t = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++)	// 枚举 4 个方向：上下左右 
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			// 判断当前点 [x, y] 是否为 X 
			if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '.') continue;	// 不是 X 则忽略该点 [x, y] 
			/*
			点[x, y]是 X ，则遍历该点： 
				1. 将该点[sx, sy]放入队列中 
				2. 将该点[sx, sy]设置为已经被遍历 X-> . 
				3. 将该点[sx, sy]放入v中 
			*/ 
			g[x][y] = '.';
			q.push({x, y});
			v.push_back({x, y});
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> g[i];
	// 1. 将两个联通块中的所有点分别放入两个数组中 
	vector<PII> v1, v2;	// 存储每个连通块中的所有点
	bool flag = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(g[i][j] == 'X' && flag) // 记录第一个连通块 
			{	
				bfs(i, j, v1);
				flag = false;
			}
			else if(g[i][j] == 'X' && !flag) // 记录第二个连通块 
				bfs(i, j, v2);
		} 
	
	// 2. 对于2个连通块进行枚举，寻找两个连通块中的最短距离
	int res = 1e9;
	for(int i = 0; i < v1.size(); i ++)
		for(int j = 0; j < v2.size(); j ++) 
		{
			int x1 = v1[i].x, y1 = v1[i].y;
			int x2 = v2[j].x, y2 = v2[j].y;
			res = min(res, abs(x1 - x2) + abs(y1 - y2));
		}
		
	cout << res - 1 << endl;	// 点的个数 = 边的个数 - 1 

	return 0;
}

