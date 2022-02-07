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
	
	// ö��ɾ����ǰ�߶�
	int res = 0;
	for(int i = 0; i < n; i ++)
	{
		// ά�� [st, ed] 
		int sum = 0, st = -1, ed = -1;
		for(int j = 0; j < n; j ++)
			if(i != j)
			{
				if(p[j].x <= ed) ed = max(ed, p[j].y);
				else	 // [x, y] �� [st, ed] �޽��� 
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

