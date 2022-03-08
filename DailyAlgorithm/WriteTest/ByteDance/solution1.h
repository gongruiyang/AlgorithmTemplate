#include "../../header.h"
int calDPDScore(string s) {
    int res = 0;
    for(int i = 0, j = 0; i < s.size(); i ++) {
        if(s[i] == 'Y') {
            j = i;
            while(j < s.size() && s[j] == 'Y') j ++;

            int cnt = j - i;
            i = j - 1;

            cout << cnt << endl;

            if(cnt <= 3) res -= 10;
            else if(cnt > 3 && cnt <= 7) res -=15;
            else res -= 25;
        }
    }
    return res;
}

//long long GetSubArrayMaxProduct(vector<long>& nums) {
//    // write code here
//    vector<long long> f(nums.size() + 1, 1);
//    f[0] = 1;
//    for(int i = 0; i < nums.size(); i ++) f[i+1] = f[i] * nums[i];
//
//    long long res = 0;
//    for(int i = 0; i < f.size(); i ++) {
//        for(int j = i + 1; j < f.size(); j ++) {
//            res = max(res, f[j] / f[i]);
//        }
//    }
//
//    return res;
//}

//
//long long res;
//long long cnt;
//
//void dfs(long long sx, long long sy, long long ex, long long ey) {
//    if(sx == ex && sy == ey) {
//        cnt = min(res, cnt);
//        return ;
//    }
//    if(sx > ex || sy > ey) return ;
//    res ++;
//    dfs(sx + 1, sy + 1, ex, ey);
//    dfs(sx * 2, sy * 2, ex, ey);
//    res --;
//}
//long long GetMinCalculateCount(long long sx, long long sy, long long ex, long long ey) {
//    // write code here
//    cnt = LONG_LONG_MAX;
//    res = 0;
//    dfs(sx, sy, ex, ey);
//    if(cnt == 0) return -1;
//    return cnt;
//}