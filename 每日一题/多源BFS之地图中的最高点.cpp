#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int> PII;
typedef vector<vector<int>> VVI;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) 
	{
		int n = g.size(), m = g[0].size();
		queue<PII> q;
		VVI ans(n, vector<int> (m, 0));
		// 将所有水域入队 
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(g[i][j] == 1)
					q.push({i, j});
				else
					ans[i][j] = -1;
		// BFS
		while(q.size())
		{
			auto e = q.front();
			q.pop();

			for(int i = 0; i < 4; i ++)
			{
				int a = e.x + dx[i], b = e.y + dy[i];
				if(a < 0 || b < 0 || a >= n || b >= m || ans[a][b] >= 0) continue;
				ans[a][b] = ans[e.x][e.y] + 1;
				q.push({a, b});
			}
		}
		return ans;
    }
};

int main()
{


	return 0;
}

