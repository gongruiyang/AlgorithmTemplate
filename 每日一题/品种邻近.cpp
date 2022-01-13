#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int N = 1e6 + 10; 
int pre[N];	// ���ڼ�¼��һ�ε�ǰid���ֵ������±� 
int n, k;

int main()
{
	memset(pre, -0x3f, sizeof pre);
	cin >> n >> k; 
	int ans = -1;
	for(int i = 1; i <= n; i++)
	{
		int id;
		cin >> id;
		if(i - pre[id] <= k) ans = max(ans, id);
		pre[id] = i;
	}
	
	cout << ans << endl;
	
	return 0;
}

