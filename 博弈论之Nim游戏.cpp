#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, res = 0;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		res ^= x;
	}
	cout << (res ? "Yes" : "No") << endl;
	return 0;
}

