#include "../header.h"
/**
 *  ACW : 1672. 疯狂的科学家
 *  tag : 双指针
 */

int n;
string a, b;

void solution() {
    cin >> n;
    cin >> a >> b;

    // 双指针寻找不同的区间，统计个数
    int res = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] != b[i]) {
            int j = i + 1;
            while(j < n && a[j] != b[j]) j ++;
            res ++;
            i = j;
        }
    }

    cout << res << endl;
}

