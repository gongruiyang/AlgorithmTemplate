#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[N][N];
int n, m;
vector<vector<int>> g;
class Solution {
public:
	int dfs(int x, int y)
	{
		int res = g[x][y];
		for(int i = 0; i < 4; i ++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || b < 0 || a >= n || b >= m || g[a][b] == 0 || vis[a][b] == true) 
				continue;
			vis[a][b] = true;
			res = max(res, g[x][y] + dfs(a, b));
			vis[a][b] = false;
		}
		return res;
	}
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        memset(vis, 0, sizeof vis);
        g = grid;
		n = g.size(), m = g[0].size();
		
		int res = 0;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(g[i][j] != 0)
				{
					vis[i][j] = true;
					res = max(res, dfs(i, j));
					vis[i][j] = false;
				}
        return res;
    }
};
