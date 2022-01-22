#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map> 
using namespace std;
vector<int> findAnagrams(string s, string p) 
{
	unordered_map<char, int> cnt;
	for(auto c : p) cnt[c]++;
	
	vector<int> res;
	int tot = cnt.size();
	// 滑动窗口 [j ,i] 
	for(int i = 0, j = 0, match = 0; i < s.size(); i ++)
	{
		// 将 i 指向的字符加入窗口 
		cnt[s[i]]--;
		if(cnt[s[i]] == 0) match++;
		while(i - j + 1 > p.size())	// 窗口大于 p.size() 
		{
			if(cnt[s[j]] == 0) match--;	//  判断 j 指向的字符是否位于 p 中
			// 将 j 指向的字符移除窗口 
			cnt[s[j]] ++;
			j ++;
		}
		if(match == tot) res.push_back(j);
	}
	return res;
}
int main()
{
	
	auto ans = findAnagrams("cbaebabacd", "abc");

	return 0;
}

