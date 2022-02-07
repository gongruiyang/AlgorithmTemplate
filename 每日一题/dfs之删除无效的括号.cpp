#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
	vector<string> ans;
    vector<string> removeInvalidParentheses(string s) 
    {
		int le = 0, ri = 0; // waiting delete  
		for(auto x : s)
		{
			if(x == '(')
				le ++;
			else if(x == ')')
			{
				if(le == 0) ri ++;
				else le --;
			}
		}
		dfs(s, 0, "", 0, le, ri); 
		return ans; 
    }
    void dfs(string& s, int u, string path, int cnt, int le, int ri)
    {
    	if(u == s.size())
    	{
    		if(!cnt) ans.push_back(path);
    		return ;
		}
		
		if(s[u] != '(' && s[u] != ')')
			dfs(s, u+1, path + s[u], cnt, le, ri);
		else if(s[u] == '(')
		{
			int k = u;
			while(k < s.size() && s[k] == '(') k ++;
			le -= k - u;
			for(int i = k - u; i >= 0; i --)
			{
				if(le >= 0) dfs(s, k, path, cnt, le, ri);
				path += '(';
				cnt ++, le ++;
			}
		}
		else if(s[u] == ')')
		{
			int k = u;
			while(k < s.size() && s[k] == ')') k ++;
			ri -= k - u;
			for(int i = k - u; i >= 0; i --)
			{
				if(cnt >= 0 && ri >= 0) dfs(s, k, path, cnt, le, ri);
				path += ')';
				cnt --, ri ++;
			}
		}
	}
};
int main()
{


	return 0;
}

