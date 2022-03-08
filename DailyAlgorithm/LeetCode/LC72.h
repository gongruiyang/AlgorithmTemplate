#include "../header.h"
/**
 *  72. 编辑距离
 *  tag : DP
 */
class LC72 {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        a = ' ' + a, b = ' ' + b;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        // 一个字符串长度为0 另一个字符串长度为i 则需要操作i次使得相等
        for(int i = 0; i <= n; i ++) f[i][0] = i;
        for(int i = 0; i <= m; i ++) f[0][i] = i;

        // f[i][j] = min{f[i-1][j] + 1, f[i][j-1] + 1, f[i-1][j-1] + 1/0}
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++) {
                f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
                f[i][j] = min(f[i][j], f[i-1][j-1] + (int)(a[i] != b[j]));
            }
        return f[n][m];
    }
};
