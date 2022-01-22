#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;
typedef pair<int,int> PII;
#define x first
#define b second
PII p[N];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int xi;
		char bi;
		cin >> xi >> bi;
		p[i].x = xi;
		if(bi == 'H') p[i].b = 1;
		else p[i].b = -1;
	}
	
	sort(p, p + n);
	// 答案可能的情况：
	// 		1. 连续 1 或 -1
	// 		2. 某连续区间内 相等个数的 1 和 -1 
	unordered_map<int, int> hash;
	int res = 0, sum = 0, last;
	for(int i = 0; i < n; i ++)
	{
		// [1, si) 
		if(!hash.count(sum))
			hash[sum] = p[i].x;
		// [1, si]
		sum += p[i].y;
		// 若 sum 已经出现过，更新等长 1 和 -1 的答案区间 
		if(hash.count(sum))
			res = max(res, p[i].x - hash[sum]);
		
		// 处理连续 1 或 -1 的情况 
		if(i == 1 || p[i].y != p[i-1].y) 
			last = p[i].x;
		// 更新连续 1 或 -1 的可能答案区间 
		res = max(res, p[i].x - last);
	}
	
	cout << res << endl;
	
	return 0;
}

