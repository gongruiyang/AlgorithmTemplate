#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) 
    {
        int n = g.size();
        if(n == 0) return 0;
        int m = g[0].size();
        
        vector<vector<int>> f(n, vector<int>(m));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(g[i][j] == 0)	// 无障碍 
                {
                    if(i == 0 && j == 0) f[i][j] = 1;	// start 点 
                    else 
                    {
                        if(i != 0) f[i][j] += f[i-1][j];    // 如果当前点左方有格子
                        if(j != 0) f[i][j] += f[i][j-1];    // 如果当前点上方有格子
                    }
                }
        return f[n-1][m-1];
    }
};

int main()
{


	return 0;
}

