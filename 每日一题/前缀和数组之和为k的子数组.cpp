#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
int subarraySum(vector<int>& nums, int k) 
{
	int n = nums.size();
	// ǰ׺������ 
	vector<int> s(n + 1);
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + nums[i - 1];
	
	unordered_map<int, int> hash;
	hash[0] = 1;	// ǰ׺��ǡ��Ϊ k �ı߽� 
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		res += hash[s[i] - k];	// �ۼ��� i ֮ǰ���ϵ� s[j] ���� 
		hash[s[i]] ++;	// ͳ�����ǰ׺�ͳ��ֶ��ٴ� 
	}
	
	return res; 
}
int main()
{
	vector<int> nums = {1, 1, 1};
	cout << subarraySum(nums, 2) << endl; 

	return 0;
}

