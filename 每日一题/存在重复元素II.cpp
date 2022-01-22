#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map> 
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i ++)
    {
        if(hash.count(nums[i]))
        {
            int j = hash[nums[i]];
            cout << i << ' ' << j << endl;
            if(abs(i - j) <= k) return true;
        }
        hash[nums[i]] = i;
    }
    return false;
}
int main()
{
	vector<int> nums = {1,0,1,1};
	cout << containsNearbyDuplicate(nums, 1) << endl;

	return 0;
}

