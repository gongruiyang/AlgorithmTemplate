#include "../header.h"

/**
 *  1696
 *  tag :
 */
const int N = 110;
int a[N], n;

void solution() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    a[n + 1] = n + 1;
    for(int i = n; i >= 1; i --) {
        if(a[i] > a[i+1]) {
            cout << i << endl;
            break;
        }
    }
}