#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std;

bool canPartition(vector<int>& nums) 
{
	int sum = 0;
	for(auto x : nums) sum += x;
	if(sum % 2) return false;
	
	// 01���� 
	int target = sum / 2;
	vector<bool> dp(target + 1, false);
	dp[0] = true;	// ��Ϊ0һ�������� 
	for(auto x : nums)
		for(int j = target; j >= x; j --)
			dp[j] = dp[j] || dp[j - x];
			
	return dp[target];  
}
int main()
{


	return 0;
}

