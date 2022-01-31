#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector> 
using namespace std;


const int N = 5e4 + 10;
int x[N], y[N], a[N], b[N];

int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i ++)
	{
		cin >> x[i] >> y[i];
		a[i] = x[i], b[i] = y[i];
	}
	
	sort(a, a + n);
	sort(b, b + n);
	
	int ans = 2e9;
	for(int i = 0; i < n; i ++)
	{
		int x1, x2, y1, y2;
		x1 = x[i] == a[0] ? a[1] : a[0];
		y1 = y[i] == b[0] ? b[1] : b[0];
		x2 = x[i] == a[n-1] ? a[n-2] : a[n-1];
		y2 = y[i] == b[n-1] ? b[n-2] : b[n-1];
		ans = min(ans, (x2 - x1)*(y2 - y1)); 
	}
	
	cout << ans << endl;

	return 0;
}

