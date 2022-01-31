#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
    	// 第一次二分：寻找分界点 
        int le = 0, ri = nums.size() - 1;
		while(le < ri)
		{
			int mid = le + ri + 1 >> 1;
			if(nums[mid] >= nums[0]) le = mid;
			else ri = mid - 1;
		} 
		
		// 第二次二分：寻找 target 的位置
		if(target >= nums[0]) le = 0;	// mid为右边界 
		else le = ri + 1, ri = nums.size() - 1;	// mid为左边界
		while(le < ri)
		{
			int mid = le + ri >> 1;
			if(nums[mid] >= target) ri = mid;
			else le = mid + 1;	
		} 
		if(target == nums[ri]) return le;
		return -1;
    }
};
int main()
{


	return 0;
}

