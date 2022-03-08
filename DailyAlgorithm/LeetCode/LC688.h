#include "../header.h"

double f[25][25][101];
int dx[] = {-2 , -1, 1, 2, 2,1 ,-1, -2};
int dy[] = {1, 2,2,1,-1,-2,-2,-1};
class LC688 {
public:
    double knightProbability(int n, int K, int row, int column) {
        memset(f, 0, sizeof f);

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                f[i][j][K] = 1;

        for(int k = K - 1; k >= 0; k --)    // 枚举步数
            for(int i = 0; i < n; i ++)     // 枚举横坐标
                for(int j = 0; j < n; j ++) // 枚举纵坐标
                    for(int u = 0; u < 8; u ++) {   // 枚举 8 个方向
                        int x = i + dx[u], y = j + dy[u];
                        if(x >= 0 && x < n && y >= 0 && y < n)
                            f[i][j][k] += f[x][y][k + 1] / 8;
                    }

        return f[row][column][0];
    }

};
