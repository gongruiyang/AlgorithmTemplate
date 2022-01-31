#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
		int res = INT_MIN;
		int f = nums[0], g = nums[0];
		for(int i = 1; i < nums.size(); i ++)
		{
			int fa = f * nums[i], ga = g * nums[i], a = nums[i];
			f = max(a, max(fa, ga));
			g = min(a, min(fa, ga));
			res = max(res, f);
		}
    	return res;
	}
};
int main()
{


	return 0;
}

