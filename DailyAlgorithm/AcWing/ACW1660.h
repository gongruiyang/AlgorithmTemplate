#include "../header.h"
/**
 *  ACW : 1660. 社交距离 II
 *  tag : 双指针 \ 贪心
 */

typedef pair<int,bool> PIB;
const int N = 1e3 + 10;
PIB d[N];
int n;

void solution() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> d[i].first >> d[i].second;

    sort(d, d + n);

    // 寻找最小传播半径
    int r = 1e8;
    for(int i = 1; i < n; i ++)
        if(d[i].second != d[i-1].second)
            r = min(r, d[i].first - d[i-1].first);
    r--;

    // 双指针 统计连通块个数
    int res = 0;
    for(int i = 0; i < n; i ++)
        if(d[i].second) {
           int j = i + 1;
           while(j < n && d[j].second && d[j].first - d[j-1].first <= r) j ++;
           res ++;  //找到一个连通块
           i = j - 1; //抵消 i++
        }

    cout << res << endl;
}