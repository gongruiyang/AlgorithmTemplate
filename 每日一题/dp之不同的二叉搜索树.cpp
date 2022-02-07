#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int numTrees(int n) 
	{
#if 0	// ¿¨ÌØÀ¼Êý 
	    long long C = 1;
        for (int i = 0; i < n; i ++) 
		{
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
#endif
		vector<int> f(n + 1);
		f[0] = 1;	 
		
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= i; j ++)
				f[i] += f[j-1] * f[i-j];
		
		return f[n]; 
    }
};

int main()
{


	return 0;
}

