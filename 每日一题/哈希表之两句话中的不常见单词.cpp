#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string, int> hash;
        int i, j;
        for(i = 0, j = 0; i < s1.size(); i ++)
        {
            if(s1[i] == ' ')
            {
                string str = s1.substr(j, i - j);
                j = i + 1;
                hash[str] ++;
            }
        }
        hash[s1.substr(j, i - j)]++;

        for(i = 0, j = 0; i < s2.size(); i ++)
        {
            if(s2[i] == ' ')
            {
                string str = s2.substr(j, i - j);
                j = i + 1;
                hash[str] ++;
            }
        }
        hash[s2.substr(j, i - j)]++;

        vector<string> res;
        for(auto e : hash)
            if(e.second == 1)
                res.push_back(e.first);
        return res;
    }
};
int main()
{


	return 0;
}

