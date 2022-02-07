#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int> PII;

const int N = 110;
int n;
PII p[N];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) 
		cin >> p[i].x >> p[i].y;
	
	sort(p, p + n);
	
	// 枚举删除当前线段
	int res = 0;
	for(int i = 0; i < n; i ++)
	{
		// 维护 [st, ed] 
		int sum = 0, st = -1, ed = -1;
		for(int j = 0; j < n; j ++)
			if(i != j)
			{
				if(p[j].x <= ed) ed = max(ed, p[j].y);
				else	 // [x, y] 与 [st, ed] 无交集 
				{
					sum += ed - st;
					st = p[j].x, ed = p[j].y;
				}
			} 
		sum += ed - st;
		res = max(res, sum);
	} 
	
	cout << res << endl;
	return 0;
}

