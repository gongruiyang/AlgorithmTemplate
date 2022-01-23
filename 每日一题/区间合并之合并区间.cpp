#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

// 区间合并模板题 
vector<vector<int>> merge(vector<vector<int>>& a)
{
	if(a.empty()) return {};
	
 	vector<vector<int>> res;
	sort(a.begin(), a.end());
	// 维护区间 [le, ri] 
	int le = a[0][0], ri = a[0][1];
	for(int i = 1; i < a.size(); i ++)
	{
		if(a[i][0] > ri)	
		{
			// 当前区间[a[i][0], a[i][1]]与正在维护的区间[le,ri]没有交集 
			res.push_back({le, ri});
			le = a[i][0], ri = a[i][1];
		}
		else	// 有交集 
			ri = max(ri, a[i][1]);
	} 
	res.push_back({le, ri});
	return res;
}

int main()
{


	return 0;
}

