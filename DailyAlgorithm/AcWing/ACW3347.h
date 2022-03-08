#include "../header.h"
/**
 *  ACW : 3347. 菊花链
 *  tag : BF
 */
const int N = 110;
int n;
int p[N];
void solution() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> p[i];

    int res = 0;
    // 暴力枚举每一个区间
    for(int i = 0; i < n; i ++)
        for(int j = i, s = 0; j < n; j ++) {
            s += p[j];  // [i,j]区间和
            int cnt = j - i + 1;    // [i,j]区间个数
            if(s % cnt == 0) {  // 若能整除
                for(int k = i; k <= j; k ++) // 枚举判断是否相等
                    if(p[k] == s / cnt) {
                        res ++;
                        break;
                    }
            }
        }
    cout << res << endl;
}