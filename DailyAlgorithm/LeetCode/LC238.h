#include "../header.h"
/**
 *  238. 除自身以外数组的乘积
 *  tag : 前后缀分解
 */
class LC238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> p(n,1);
        // 前缀积数组
        for(int i = 1; i < n; i ++)
            p[i] = p[i-1] * nums[i-1];
        // s 存储后缀积中间值， ans[i] = p[i] * s[i]
        for(int i = n-1, s = 1; i >= 0; i --) {
            p[i] *= s;
            s *= nums[i];
        }
        return p;
    }
};