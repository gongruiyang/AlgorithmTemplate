#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// 二分 
void solution1()
{
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	
	for(auto i = a.begin(); i != a.end(); i ++)
	{
		auto le = i, ri = i;	// 引爆每一个点最大能研延伸到的左右边界 
		int tle = 1, tri = 1;	// 爆炸半径
		// 寻找 大于等于  *le - tle 的边界 le 
		while(lower_bound(a.begin(), le, *le - tle) != le)
		{
			// 每次都引爆最左边界的草堆 
			le = lower_bound(a.begin(), le, *le - tle);
			tle ++;	 
		}
		// 寻找 小于等于  *ri + tri 的边界 ri 
		while(--upper_bound(ri, a.end(), *ri + tri) != ri)
		{
			// 每次都引爆最右边界的草堆 
			ri = --upper_bound(ri, a.end(), *ri + tri);
			tri ++;
		}
		// 获取引爆当前点的最大范围 
		ans = max(ans, (int)(ri - le + 1));
	}
	cout << ans << endl;	
}

// BFS
void solution2()
{	
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> hash; // <点xi : 状态> 
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		hash[a[i]] = -1;	// 初始状态设置为 -1 
	}
	
	// 枚举每一个点 
	for(int i = 0; i < n; i ++)
	{
		auto copy = hash;	// 备份 hash 表 
		copy[a[i]] = 1; 	// 将当前第 i 个点设置为初始引爆点 
		
		queue<int> q;
		q.push(a[i]);
		int num = 0; //用来记录当前点最大能引爆多少个点
		while(q.size())
		{
			int t = q.front();	// 当前引爆点 
			q.pop();
			num ++;
			
			// 引爆 [t - copy[t], t + copy[t]] 范围内的点 
			for(int k = -copy[t]; k <= copy[t]; k ++)
			{
				if(copy[t + k] == -1)	// 第 t + k 点还未被引爆，则引爆 
				{
					q.push(t + k);
					// 当前点的引爆半径为上一个点的半径 + 1 
					copy[t + k] = copy[t] + 1;
				} 
			}
		} 
		ans = max(ans, num); 
	} 
	cout << ans << endl;
} 

int main()
{
	solution2();

	return 0;
}

