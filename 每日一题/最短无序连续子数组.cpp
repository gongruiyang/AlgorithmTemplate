#include <iostream>
#include <algorithm>
#include <cstring>
#include <map> 
using namespace std;

const int N = 1e5 + 10;
int f[N], g[N];
int n, m;
int maxLCS;

int minOperations(vector<int>& target, vector<int>& arr) 
{
	// 初始化全局变量 
	n = target.size(), m = arr.size();
	memset(g, 0x3f3f3f3f, sizeof g);
	
	// 将 target 数组 value -> idx 的映射关系 
	map<int, int> hash;
	for(int i = 0; i < n; i++) hash[target[i]] = i;
	
	// 将 target 与 arr 中的公共元素 x 位于 target 数组中的下标 dix 放入数组 nums 中 
	vector<int> nums;
	for(int i = 0; i < m; i++)
	{
		int x = arr[i];
		if(hash.count(x))
		{
			int idx = hash[x];
			nums.push_back(idx); 
		} 
	}
	
	// 构建 g 和 f 数组，并求出 最长LIS 的长度 maxLCS 
	int size = nums.size();
	for(int i = 0; i < size; i++)
	{
		// 在 g 数组中寻找 g[idx] < nums[i] 的分割点 idx
		int le = 0, ri = size; 
		while(le < ri)
		{
			int mid = le + ri + 1 >> 1;
			if(g[mid] < nums[i]) le = mid;
			else ri = mid - 1;
		}
		int idx = ri + 1; 
		f[i] = f[idx] + 1;
		g[idx] = min(g[idx], nums[i]);
		maxLCS = max(maxLCS, idx);
	}
	return n - maxLCS;
}

int main()
{
	vector<int> target = {5,10,8,11,3,15,9,20,18,13};
	vector<int> arr	   = {15,8,2,9,11,20,8,11,7,2};
	cout << minOperations(target, arr); 

	return 0;
}

