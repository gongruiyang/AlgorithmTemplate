#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
int subarraySum(vector<int>& nums, int k) 
{
	int n = nums.size();
	// 前缀和数组 
	vector<int> s(n + 1);
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + nums[i - 1];
	
	unordered_map<int, int> hash;
	hash[0] = 1;	// 前缀和恰好为 k 的边界 
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		res += hash[s[i] - k];	// 累加上 i 之前符合的 s[j] 个数 
		hash[s[i]] ++;	// 统计这个前缀和出现多少次 
	}
	
	return res; 
}
int main()
{
	vector<int> nums = {1, 1, 1};
	cout << subarraySum(nums, 2) << endl; 

	return 0;
}

