#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

#define x first
#define y second
typedef pair<int,int> PII;
const int N = 1e3 + 10;

bool g[N][N];//�洢�����иɲݶ�
int dist[N][N];//����i,j��Ҫ�Ƴ��ɲݶѵ���С����
int n,x,y;
int row, col;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

deque<PII> q;//˫�˶��� ˫��bfs
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
            int a = t.x + dx[i], b = t.y + dy[i];//�����µĵ�
            if(a < 0 || a > row || b < 0 || b > col || dist[a][b] <= dist[t.x][t.y] + g[a][b]) continue;
            dist[a][b] = dist[t.x][t.y] + g[a][b];
            // ��ȨΪ0�Ŷ��� Ϊ1�Ŷ�β
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
        g[a][b] = true;//�иɲݶ�
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
int g[N][N], ans[N][N];	// g �洢 01 ��ͼ�� ans �洢�ߵ�ÿһ��������Ҫ�Ƴ����ٸ��ɲݶ� 
int row, col;	// g �� ans ����󳤺Ϳ� 
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs(int sx, int sy)
{
	//  �� ans ÿһ�����Ӷ���ʼ��Ϊ������ 
	memset(ans, 0x3f, sizeof ans);
	 
	queue<PII> q;
	q.push({sx, sy});
	ans[sx][sy] = 0;	// ��ʼλ����Ҫ�Ƴ��ĸɲݶ�Ϊ 0 
	while(!q.empty())
	{
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 4; i ++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			// ��Ҫ�ų��ĵ㣺1. ���ڵ�ͼ�е� 2. �˵�� ans �ȴ� [x,y] ��������ĸɲݶ�ҪС ����Ҫ���޸Ĵ˵� 
			if(x < 0 || y < 0 || x > row || y > col || ans[x][y] <= ans[t.x][t.y] + g[x][y]) continue;
			// ���� ans : �� [t.x, t.y] �ﵽ [x, y] ����Ҫ�ĸɲݶ� 
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
		row = max(row, x), col = max(col, y);	// ͳ�Ƶ�ͼ�ı߽� ��������ʵ��û�б߽�ģ�ͳ�Ʊ߽���Ϊ���Ż����ٱ���һЩ�㣩 
		g[x][y] = 1;
	}
	row ++, col ++;	// �߽� + 1 Ҳ�ǿ����ߵ� 
	cout << bfs(sx, sy) << endl;
	
	return 0;
}

#endif
