#include <iostream>
#include <algorithm>
#include <queue> 
#include <cstring>
using namespace std; 
typedef pair<int, int> PII;

const int N = 1e2 + 10;
int n, m;
int g[N][N];	// 用于保存地图 
int d[N][N];	// 每一个格子中的数字表示走到当前格子所需要的步数 
queue<PII> q;	// 使用队列来做BFS 
// 方向坐标 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// 用于保存路径 
PII path[N][N];
vector<PII> bestPath;	// 保存最优路径 

int bfs()
{
	memset(d, -1, sizeof d);	// 初始化路径图 
	d[0][0] = 0;	// 左上角为起点 
	q.push(make_pair(0, 0));	// 左上角点入队列开始BFS 
	while(!q.empty())
	{
		PII head = q.front();
		q.pop();
		// 搜索四个方向 
		for(int i = 0; i < 4; i++)
		{
			// 获取当前方向坐标 
			int x = head.first + dx[i], y = head.second + dy[i];
			// 判断当前位置是否能走 
			if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				// 可以走表示能入队列，并更新走到当前位置所需步数 
				d[x][y] = d[head.first][head.second] + 1;	// 当前步数 = 上一个格子步数 + 1 
				q.push(make_pair(x, y));
				path[x][y] = head; // 表示从 t 走到当前格子的 
			}
		}
	}
	
	// 寻找到最优路径 
	int x = n - 1, y = m - 1;
	while(x || y)
	{
		bestPath.push_back(make_pair(x, y));
		PII lastStep = path[x][y];
		x = lastStep.first, y = lastStep.second;
	} 
	bestPath.push_back(make_pair(0, 0));
	reverse(bestPath.begin(), bestPath.end());
	
	// 返回走到右下角所需步数 
	return d[n-1][m-1];
}

int main()
{
	cin >> n >> m;
	// 初始化地图 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
		
	cout << "最少步数：" << bfs() << endl;
	cout << "最优路径：" << endl; 
	for(vector<PII>::iterator step = bestPath.begin(); step != bestPath.end(); step++)
	{
		cout << (*step).first << " " << (*step).second << endl; 
	}
	return 0;
}
