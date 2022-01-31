#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	unordered_map<string, vector<string>> hash;
	for(auto s : strs)
	{
		// 对 s 的备份进行排序 
		string cp = s;
		sort(cp.begin(), cp.end());
		// 将 s 存到对应的组内 
		hash[cp].push_back(s);
	}
	
	// 将哈希表中所有的元素的 vector 数组放到 res 数组中即为答案 
	vector<vector<string>> res;
	for(auto p : hash)
		res.push_back(p.second);
	
	return res;
}
int main()
{
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"}; 
	auto res = groupAnagrams(strs);
	for(auto v : res)
	{
		for(auto s : v)
			cout << s << ' ';
		cout << endl;
	}
	return 0;
}

