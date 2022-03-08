#include "../header.h"

/**
 *  239. 滑动窗口最大值
 *  tag : 单调队列
 */
class LC239 {
public:
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;   // 存储下标，值单调递减
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++) {
            // 维持滑动窗口大小
            if(q.size() && i - k + 1 > q.front()) {
                q.pop_front();
            }
            // 将队列中所以比当前元素值小的元素删除
            while(q.size() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            // 判断
            if(i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
