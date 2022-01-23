#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <unordered_map> 
using namespace std;


// 计数排序 
vector<int> topKFrequent(vector<int>& nums, int k) 
{
	// 建立 <nums : cnts> 映射 
	unordered_map<int, int> cnt;
	for(auto x : nums) cnt[x] ++;
	
	// s[c] = i : 出现 c 次的有 i 个数 
	int n = nums.size();
	vector<int> s(n + 1);
	for(auto [x, c] : cnt) s[c] ++;
	
	//	找到出现次数最多的前 k 个数的频率分解线 i 
	int i = n, t = 0;
	while(t < k)
	{
		t += s[i];
		i --;	
	} 
	
	// 将所有频率大于 i 的全部加入到答案中
	vector<int> res;
	for(auto [x, c] : cnt)
		if(c > i) res.push_back(x);
	return res; 
}

int main()
{


	return 0;
}

