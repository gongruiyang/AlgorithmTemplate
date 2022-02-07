#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 110;
const string gins = "AGCT";
int n, m;
char a[N][N], b[N][N];

int main()
{
	cin >> n >> m; 
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	
	int res = 0;
	// 枚举每一位基因 
	for(int i = 0; i < m; i ++)
	{
		// 将斑点牛的第 i 列基因放入哈希表中 
		bool hash[4] = {};
		for(int j = 0; j < n; j ++)
			hash[gins.find(a[j][i])] = true;
		
		// 判断普通牛的基因是否在哈希表中出现
		bool flag = true;
		for(int j = 0; j < n; j ++)
			if(hash[gins.find(b[j][i])]) 
				flag = false;
		// 如果两部分没有交集，则表示找到一列符合题意 
		if(flag) res ++;
	}
	
	cout << res << endl;

	return 0;
}

