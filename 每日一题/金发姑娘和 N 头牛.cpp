#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int main()
{

	int n, x, y, z;
	cin >> n >> x >> y >> z;
	
	// map 差分 三个区间： [0, A]  [A, B] [B, infinity] 
	map<int, int> m;
	while(n --)
	{
		int le, ri;
		cin >> le >> ri;
		m[0] += x;
		m[le] = m[le] - x + y;
		m[ri + 1] = m[ri + 1] - y + z;
	}
	
	
	int mx = 0, cur = 0;
	for(auto e : m)
	{
		cur += e.second;
		if(cur > mx) mx = cur;
	}
	
	cout << mx << endl;
	
	return 0;
}

