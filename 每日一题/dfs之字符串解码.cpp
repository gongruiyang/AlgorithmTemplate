#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string dfs(string s, int& u)
{
	string res;
	while(u < s.size() && s[u] != ']')
	{
		if(s[u] >= 'a' && s[u] <= 'z' || s[u] >= 'A' && s[u] <= 'Z')
			res += s[u++];
		else if(s[u] >= '0' && s[u] <= '9')
		{
			// 取出数字 k 
			int cur = u;
			while(s[cur] >= '0' && s[cur] <= '9') cur ++;
			int k = stoi(s.substr(u, cur - u));
			// dfs + 回溯 
			u = cur + 1;	// 去左括号 
			string y = dfs(s, u);
			u ++;			// 去右括号 
			// 将 y 重复 k 次，接到答案后面 
			while(k --) res += y;
		}
		//
	}
	return res;
}
string decodeString(string s) 
{
	int u = 0;
	return dfs(s, u);
}
int main()
{
	cout << decodeString("3[a2[c]]") << endl; 

	return 0;
}

