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
	// �������� [j ,i] 
	for(int i = 0, j = 0, match = 0; i < s.size(); i ++)
	{
		// �� i ָ����ַ����봰�� 
		cnt[s[i]]--;
		if(cnt[s[i]] == 0) match++;
		while(i - j + 1 > p.size())	// ���ڴ��� p.size() 
		{
			if(cnt[s[j]] == 0) match--;	//  �ж� j ָ����ַ��Ƿ�λ�� p ��
			// �� j ָ����ַ��Ƴ����� 
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

