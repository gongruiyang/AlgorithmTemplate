#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
	{
		int n = h.size();
		vector<int> le(n), ri(n); // 每个数左/右边第一个比它小的数的位置
		
		// 构建 le 数组 从左向右扫描,构建 ri 数组 从右向左扫描
		stack<int> stk;
		for(int i = 0; i < n; i ++)
		{
			while(stk.size() && h[stk.top()] >= h[i])
				stk.pop();
				
			if(stk.empty()) le[i] = -1;
			else le[i] = stk.top();
			
			stk.push(i);
		}
		while(stk.size()) stk.pop();
		for(int i = n-1; i >= 0; i --)
		{
			while(stk.size() && h[stk.top()] >= h[i])
				stk.pop();
				
			if(stk.empty()) ri[i] = n;
			else ri[i] = stk.top();
			
			stk.push(i);
		}
		
		// 枚举每个上边界
		int res = 0;
		for(int i = 0; i < n; i ++)
			res = max(res, (ri[i] - le[i] - 1) * h[i]); 
		return res;
    }
};
int main()
{


	return 0;
}

