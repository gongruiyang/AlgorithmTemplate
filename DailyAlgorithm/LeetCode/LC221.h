#include "../header.h"

/**
 *  221. 最大正方形
 *  tag : DP
 */
class LC221 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        int res = 0;
        for (int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                if(matrix[i-1][j-1] == '1')
                {
                    f[i][j] = min(f[i-1][j] + 1, min(f[i][j-1] + 1, f[i-1][j-1] + 1));
                    res = max(res, f[i][j]);
                }
        return res;
    }
};