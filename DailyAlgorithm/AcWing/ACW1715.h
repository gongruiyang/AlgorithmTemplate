#include "../header.h"
/**
 *  1715. 桶列表
 *  tag : 差分
 */
const int N = 1010;
int n;
int b[N];
void solution() {
    cin >> n;
    while(n --) {
        int le, ri, c;
        cin >> le >> ri >> c;
        b[le] += c, b[ri] -= c;
    }

    int res = 0, sum = 0;
    for(int i = 1; i <= 1000; i ++) {
        sum += b[i];
        res = max(res, sum);
    }

    cout << res << endl;
}