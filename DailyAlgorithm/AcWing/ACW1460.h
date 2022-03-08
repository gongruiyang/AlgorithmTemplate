#include "../header.h"
/**
 *  1460. 我在哪？
 *  tag : 二分+字符串哈希
 */
int n;
string str;
bool check(int mid) {
    unordered_set<string> hash;
    for(int i = 0; i + mid - 1 < str.size(); i ++ ) {
        auto s = str.substr(i, mid);
        if(hash.count(s)) return false;
        hash.insert(s);
    }
    return true;
}

void solution() {
    cin >> n;
    cin >> str;
    int le = 1, ri = n;
    while(le < ri) {
        int mid = le + ri >> 1;
        if(check(mid)) ri = mid;
        else le = mid + 1;
    }
    cout << ri << endl;
}