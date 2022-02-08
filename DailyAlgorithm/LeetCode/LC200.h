#include "../header.h"
/**
 *  200. 岛屿数量
 *  tag : Flood Fill / BFS
 */
class LC200 {
public:
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(int x, int y) {
        g[x][y] = 0;
        for(int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < g.size() && b >= 0 && b < g[a].size() && g[a][b] == '1') continue;
            dfs(a, b);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int res = 0;
        for(int i = 0; i < g.size(); i ++)
            for(int j = 0; j < g[0].size(); j ++)
                if(g[i][j] == '1'){
                    dfs(i, j);
                    res ++;
                }
        return res;
    }
};
