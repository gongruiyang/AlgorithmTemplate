#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& m) 
{
 	// 1. 沿着对角线翻转
	int n = m.size();
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < i; j ++)
			swap(m[i][j], m[j][i]);
	// 2. 沿着竖直对称翻转 
	for(int i = 0; i < n; i ++)
	{
		int le = 0, ri = n - 1;
		while(le < ri)
		{
			swap(m[i][le], m[i][ri]);
			le ++, ri --;
		}
	}
}
int main()
{
	vector<vector<int>> m;
	m.push_back({5,1,9,11});
	m.push_back({2,4,8,10});
	m.push_back({13,3,6,7});
	m.push_back({15,14,12,16});
	rotate(m);
	
	for(auto v : m)
	{
		for(auto x : v)
			cout << x << ' ';
		cout << endl;
	}
		
	return 0;
}

