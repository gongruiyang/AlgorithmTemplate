#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& g) 
    {
		int n = g.size();
		if(!n) return 0;
		int m = g[0].size();
		
		vector<vector<int>> f(n, vector<int>(m, INT_MAX));
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < m; j ++)
			{
				if(!i && !j) f[i][j] = g[i][j];
				else
				{
					if(i) f[i][j] = min(f[i][j], f[i - 1][j] + g[i][j]);
					if(j) f[i][j] = min(f[i][j], f[i][j - 1] + g[i][j]);
				}
			}
		}
		return f[n-1][m-1];
    }
};
int main()
{
	
	
	return 0;
}

