#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int maxProfit(vector<int>& p) 
{
    int n = p.size(), INF = 1e8;
    vector<vector<int>> f(n, vector<int>(3, -INF));
    // i: 1~n  j : 0代表冷冻期或啥也不干 1代表买入 2代表卖出 
    f[0][1] = -p[0], f[0][0] = 0;	// 第0天 买入或者不买
    for(int i = 1; i < n; i ++)
    {
        f[i][0] = max(f[i-1][0], f[i-1][2]);
        f[i][1] = max(f[i-1][1], f[i-1][0] - p[i]);
        f[i][2] = f[i-1][1] + p[i];
    }
    return max(f[n-1][0], max(f[n-1][1], f[n-1][2]));
}
int main()	
{
	cout << maxProfit({1,2,3,0,2}) << endl;

	return 0;
}

