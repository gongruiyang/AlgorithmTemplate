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
		vector<int> le(n), ri(n); // ÿ������/�ұߵ�һ������С������λ��
		
		// ���� le ���� ��������ɨ��,���� ri ���� ��������ɨ��
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
		
		// ö��ÿ���ϱ߽�
		int res = 0;
		for(int i = 0; i < n; i ++)
			res = max(res, (ri[i] - le[i] - 1) * h[i]); 
		return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
	{
		int n = matrix.size();
		if(!n) return 0;
		int m = matrix[0].size();
		
		vector<vector<int>> h(n, vector<int>(m));// ÿ���������ж��ٸ�������1 
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(matrix[i][j] == '1')
				{
					if(i) h[i][j] = 1 + h[i-1][j];
                    else h[i][j] = 1;
				}
        // ö��ÿ���±߽�
		int res = 0;
		for(int i = 0; i < n; i ++)
			res = max(res, largestRectangleArea(h[i]));
		return res;
    }
};
int main()
{


	return 0;
}

