#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110, INF = 1e8;
int e[N], ne[N], d[N], n; // d 表示入度 
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> e[i];
	e[0] = -INF, e[n+1] = INF;
	sort(e + 1, e + 1 + n);
	
	// 构建 ne 和 d 数组 
	for(int i = 1; i <= n; i ++)
		if(e[i] - e[i-1] <= e[i + 1] - e[i])	// 右边 <= 左边 
		{
			ne[i] = i - 1;	// i 指向 i-1 
			d[i - 1] ++;	// i-1 入度 +1 
		}
		else
		{
			ne[i] = i + 1;	// i 指向 i+1
			d[i + 1] ++;	// i+1 入度 +1 
		}
	
	int res = 0;
	for(int i = 1; i <= n ; i ++)
		if(d[i] == 0) 	// 该点是连通块的起始点 
			res += 2;
		else if(ne[ne[i]] == i && d[i] == 1 && d[ne[i]] == 1) // 该点在环内且不挂载树 
			res += 1; 
		
	cout << res / 2 << endl; 
		 
	return 0;
}

