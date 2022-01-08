#include <iostream>
#include <algorithm>
using namespace std;

#define height first
#define pos second
const int N = 1e5 + 10;

int n;
typedef pair<int, int> PII;
PII a[N];	// 存放 n 个田地的 位置 和 高度 
bool vis[N];	// 存储 n 个田地是否被淹没的状态：0表示没被淹没  1表示被淹没 

int main()
{
	// 1. 将 n 个田地的 顺序 和 高度 读入 a 数组中去 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		a[i].pos    = i;
		a[i].height = h;
	}
	// 2. 按照高度排序：低洼的在前面 
	sort(a, a + n);
	
	int ans = 1, cnt = 1;
	for(int i = 0; i < n; i++)
	{
		// 将当前位于 cur 处的田地淹没
		int cur = a[i].pos;
		vis[cur] = 1;
		// 判断 cur 两边的淹没状态：未被淹没的状态 -> true 
		bool le = ((cur - 1 >= 0) && !vis[cur - 1]);
		bool ri = ((cur + 1 <  n) && !vis[cur + 1]);
		if(le && ri) cnt ++;	// 都没被淹没 
		else if(!le && !ri) cnt --;	// 都被淹没
		// 判断是否需要更新 ans : 之所以需要判断是因为防止出现连续几个相同高度的田地 
		if(i == n - 1 || a[i].height != a[i+1].height)
			ans = max(ans, cnt); 
	}
	
	cout << ans << endl;
	
	return 0;
}
