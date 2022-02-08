#include "../header.h"
/**
 *  1001.网格照明
 *  tag : DFS  八皇后
 */
class LC1001 {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries)
    {
        unordered_map<int, unordered_set<int>> row, col, dg, udg;
        // 将每个灯 [x,y] 放入其所在的 行 列 正对角线 反对角线 中
        for(auto& p : lamps) {
            int x = p[0], y = p[1];
            row[x].insert(y);
            col[y].insert(x);
            dg[y-x].insert(x);
            udg[y+x].insert(x);
        }

        vector<int> res;
        for(auto& q : queries) {
            int x = q[0], y = q[1];
            // 判断 [x,y] 所在的 行 列 对角线 反对角线 是否有灯
            if(row[x].size() || col[y].size() || dg[y-x].size() || udg[x+y].size()) {
                res.push_back(1);
                // 熄灭 [x,y] 周边 8 个格子中的灯
                for(int i = x-1; i <= x+1; i ++)
                    for(int j = y-1; j <= y+1; j ++){
                        // 熄灭 [i,j]
                        row[i].erase(j);
                        col[j].erase(i);
                        dg[j-i].erase(i);
                        udg[i+j].erase(i);
                    }
            } else res.push_back(0);
        }
        return res;
    }
};