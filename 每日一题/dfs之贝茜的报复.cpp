#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<char, int> odd;		// <字母 : 偶数次数> 
unordered_map<char, int> uneven;	// <字母 : 奇数次数>
unordered_map<char, int> a;			// <字母 : 数值> 
const string S = "BESIGOM";
int ans, n;
// 表达式化简：(B + I)*(G + O + E + S)*(M) 
// key : 保证其中一个表达式为偶数即可 
void dfs(int u, int x)
{
	if(u == 7)
	{
		// 所有表达式都是奇数的情况 
		if((a['B'] + a['I']) % 2 && (a['G'] + a['O'] + a['E'] + a['S']) % 2 && a['M'] % 2)
			return ;
		// 存在表达式为偶数的情况
		ans += x;
		return ; 
	}
	char ch = S[u];
	a[ch] = 1;	// 枚举奇数情况 
	dfs(u + 1, x * uneven[ch]);	 
	a[ch] = 2;	// 枚举偶数情况 
	dfs(u + 1, x * odd[ch]);
}

int main()
{
	cin >> n;
	while(n --)
	{
		char c;
		int x;
		cin >> c >> x;
		if(x % 2) uneven[c] ++;
		else odd[c] ++;
	}
	dfs(0, 1);
	cout << ans << endl;
	
	return 0;
}

