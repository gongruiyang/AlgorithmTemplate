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
		// �� s �ı��ݽ������� 
		string cp = s;
		sort(cp.begin(), cp.end());
		// �� s �浽��Ӧ������ 
		hash[cp].push_back(s);
	}
	
	// ����ϣ�������е�Ԫ�ص� vector ����ŵ� res �����м�Ϊ�� 
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

