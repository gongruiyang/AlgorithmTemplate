#include "../header.h"
/**
 *  1443. 拍照
 *  tag : 枚举
 */

const int N = 1e3 + 10;
int n, a[N], b[N];
bool st[N]; // 判断数是否出现过

bool check(int a1) {
    memset(st, 0, sizeof st);

    a[1] = a1;
    st[a1] = true;

    // 判断 a[i]是否合法，合法条件 [1,n]且不重复
    for(int i = 2; i <= n; i ++) {
        a[i] = b[i - 1] - a[i - 1];
        if(a[i] < 1 || a[i] > n || st[a[i]]) return false;

        st[a[i]] = true;
    }
    return true;
}

void solution() {
    cin >> n;
    for(int i = 1; i < n; i ++) cin >> b[i];

    for(int i = 1; i <= n; i ++) {  // 枚举 a1 [1, n]
        if(check(i))
            break;
    }
    for(int i = 1; i <= n; i ++) cout << a[i] << ' ';
}


