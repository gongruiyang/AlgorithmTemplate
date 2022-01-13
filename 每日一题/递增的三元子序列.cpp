#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool increasingTriplet(vector<int>& nums) 
{
    int n = nums.size(), ans = 1;
    vector<int> f(n + 1, INT_MAX);
    for(int i = 0; i < n; i++)
    {
        int le = 1, ri = i + 1;
        while(le < ri)
        {
            int mid = le + ri >> 1;
            if(f[mid] >= nums[i]) ri = mid;
            else le = mid + 1;
        }
        f[ri] = nums[i];
        ans = max(ans, ri);
    }
    return ans >= 3;
}

int main()
{
	vector<int> nums = {2,6,4,8,10,9,15};
	cout << increasingTriplet(nums) << endl; 

	return 0;
}

