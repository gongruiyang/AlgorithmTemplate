#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int N = 1e3 + 10;
int a[N];
int n; 

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    // 建立 <位置，顺序> 映射
    map<int, int> m;
    for(int i = 1; i <= n; i ++) m[a[i]] = i;


    int res = 0;
    for(int i = 1; i <= n - 1; i ++)
        for(int j = i + 1; j <= n; j ++)
        {
            // 定位 [j + len, j + 2 * len] ，两边都是闭区间
            int len = a[j] - a[i];
            if(m.lower_bound(a[j] + len) == m.end()) continue;  // 区间不存在
            auto le = m.lower_bound(a[j] + len);    // 寻找比 v[j] + len      小或等 的值
            auto ri = m.upper_bound(a[j] + len * 2);// 寻找比 v[j] + 2 * len  大     的值
            ri --;                                  // 寻找比 v[j] + 2 * len  小或等 的值
            res += ri->second - le->second + 1;     // 将当前区间点个数计入答案中
        }
    cout << res << endl;

    return 0;
}
