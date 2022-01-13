#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	// 1. 构造差分 map 
	map<int, int> hash;
	int cur = 0;	// 用于记录当前走到了哪 
	for(int i = 0; i < n; i ++)
	{
		int steps;
		char dir;
		cin >> steps >> dir;
		if(dir == 'R')	// 待更新区间[cur, cur + steps]
			hash[cur] += 1, hash[cur + steps + 1] -= 1, cur += steps;
		else 			// 待更新区间[cur - steps, cur]
			hash[cur - steps] += 1, hash[cur + 1] -= 1, cur -= steps;
	}
	
	// 2. 计算前缀和数组
	int nums = 0;	// 用于记录当前位置油漆层数 
	int ans = 0;	// 用于记录所有符合条件区间的长度之和 
	int le;	//用于记录每一个符合条件区间的左边界 
	for(auto e : hash)
	{
		int k = e.first;
		int change = e.second;
		
		if(nums <= 1 && nums + change >= 2) 	// nums从 <2 变成 >=2 说明来到了新的区间的左边界，及新区间的左边界为 k 
			le = k;
		else if(nums >= 2 && nums + change <= 1) // nums从 >=2 变成 <2 说明来到了新的区间的右边界，及新区间的右边界为 k - 1 
			ans += k - 1 - le;	// 计算新区间[le, k-1]中油漆段的长度 
	
		nums += change;	// 更新 nums 
	}
	cout << ans << endl;

	return 0;	
}
