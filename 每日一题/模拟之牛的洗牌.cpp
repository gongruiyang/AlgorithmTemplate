#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int n;
int a[N], id[N];


int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) cin >> id[i];
	
	for(int k = 0; k < 3; k ++)
	{
		int p[N];
		for(int i = 1; i <= n; i ++)
			p[i] = id[a[i]];
		for(int i = 1; i <= n; i ++) id[i] = p[i];
	}
	
	for(int i = 1; i <= n; i ++) cout << id[i] << endl;
	
	
	return 0;
}

