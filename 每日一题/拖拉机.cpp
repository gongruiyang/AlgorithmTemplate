#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

#define x first
#define y second
typedef pair<int,int> PII;
const int N = 1e3 + 10;

bool g[N][N];//存储哪里有干草堆
int dist[N][N];//到达i,j需要移除干草堆的最小数量
int n,x,y;
int row, col;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

deque<PII> q;//双端队列 双端bfs
int bfs(int sx,int sy)
{
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;
    q.push_front({sx,sy});
    
    while(q.size())
    {
        PII t = q.front();
        q.pop_front();
        if(t.x == 0 && t.y == 0) return dist[0][0];
        for(int i = 0; i < 4; ++i)
        {
            int a = t.x + dx[i], b = t.y + dy[i];//计算新的点
            if(a < 0 || a > row || b < 0 || b > col || dist[a][b] <= dist[t.x][t.y] + g[a][b]) continue;
            dist[a][b] = dist[t.x][t.y] + g[a][b];
            // 边权为0放队首 为1放队尾
            if(g[a][b])
                q.push_back({a,b});
            else
                q.push_front({a,b});
        }
    }
    return dist[0][0];
}

int main()
{
    cin >> n >> x >> y;
    for(int i = 0; i < n; ++i)
    {
        int a,b;
        cin >> a >> b;
        row = max(row, a), col = max(col, b);
        g[a][b] = true;//有干草堆
    }
    row ++, col ++;
    cout << bfs(x,y) << endl;
    return 0;
}


#if 0 // BFS 

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1e3 + 10;
int g[N][N], ans[N][N];	// g 存储 01 地图， ans 存储走到每一个格子需要移除多少个干草堆 
int row, col;	// g 和 ans 的最大长和宽 
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs(int sx, int sy)
{
	//  将 ans 每一个格子都初始化为正无穷 
	memset(ans, 0x3f, sizeof ans);
	 
	queue<PII> q;
	q.push({sx, sy});
	ans[sx][sy] = 0;	// 起始位置需要移除的干草堆为 0 
	while(!q.empty())
	{
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 4; i ++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			// 需要排除的点：1. 不在地图中的 2. 此点的 ans 比从 [x,y] 到达所需的干草堆要小 则不需要再修改此点 
			if(x < 0 || y < 0 || x > row || y > col || ans[x][y] <= ans[t.x][t.y] + g[x][y]) continue;
			// 更新 ans : 从 [t.x, t.y] 达到 [x, y] 所需要的干草堆 
			ans[x][y] = ans[t.x][t.y] + g[x][y]; 
            q.push({x, y});
		}
	}

	return ans[0][0];
}

int main()
{
	int n, sx, sy;
	cin >> n >> sx >> sy;
	while(n --)
	{
		int x, y;
		cin >> x >> y;
		row = max(row, x), col = max(col, y);	// 统计地图的边界 （该题其实是没有边界的，统计边界是为了优化，少遍历一些点） 
		g[x][y] = 1;
	}
	row ++, col ++;	// 边界 + 1 也是可以走的 
	cout << bfs(sx, sy) << endl;
	
	return 0;
}

#endif
