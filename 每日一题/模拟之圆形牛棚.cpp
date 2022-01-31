#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;
int p[N];
int n;
 

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i];
	
	int res = INT_MAX;
	for(int i = 0; i < n; i ++)
	{
		int tmp = 0;
		for(int k = 0, j = i; k < n; k ++, j ++)
		{
			if(j == n) j = 0;
			tmp += p[j] * k;
		}
		res = min(res, tmp);
	}
	
	cout << res << endl;
	
	return 0;
}

