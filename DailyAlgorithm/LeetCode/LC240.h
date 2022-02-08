#include "../header.h"

class LC240 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        // 从右上角开始搜索
        int a = 0, b = m-1;
        while(a < n && b >= 0)
        {
            if(matrix[a][b] == target)
                return true;
            else if(matrix[a][b] > target) b --;
            else a ++;
        }
        return false;
    }
};