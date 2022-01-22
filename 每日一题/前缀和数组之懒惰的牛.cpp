#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define x first
#define g second
typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII a[N];
int d[N], pre[N];
int n, k, ans;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i].g >> a[i].x; 
	
	sort(a, a + n);
		
	pre[0] = 0;
	for(int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i - 1].g;
	for(int i = 0; i < n; i ++)
		d[i] = a[i].x;
	 
	for(int i = 0; i < n; i ++)
	{
		int cur = d[i];
		int len = upper_bound(d, d + n, cur + 2 * k) - d;
		ans = max(ans, pre[len] - pre[i]);
	}
	
	cout << ans << endl;
	
	
	return 0;
}

