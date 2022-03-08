#include "../header.h"

class LC76 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for(auto c : t) ht[c] ++;

        string res;
        int cnt = 0;    // [i, j]中覆盖t中字符的个数
        for (int i = 0, j = 0; i < s.size(); ++i) {
            hs[s[i]] ++;
            // 当前字符为有效字符时 cnt ++
            if(hs[s[i]] <= ht[s[i]]) {
                cnt ++;
            }
            // j 指向的字符已经是无效字符时 j ++
            while(hs[s[j]] > ht[s[j]]) {
                hs[s[j]] --;
                j ++;
            }
            // 发现一个可能答案
            if(cnt == t.size()) {
                if(res.empty() || i - j + 1 < res.size()) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};
