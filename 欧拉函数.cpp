#include <iostream>
using namespace std;

// 求 1~N 中与 N 互质的数的个数 
int phi(int x)
{
	int res = x;
	for(int i = 2; i <= x / i; i++)
	{
		if(x % i == 0)	// 找到一个质因数 i 
		{
			// res = res * (1 - 1 / i) 
			res = res / i * (i - 1);
			while(x % i == 0)
			{
				x /= i;
			}
		}
	}
	if(x > 1) 
		res = res / x * (x - 1);
	return res;
}

int main()
{
	int n;
	cin >> n;
	
	while(n--)
	{
		int x;
		cin >> x;
		cout << phi(x) << endl;
	}	
	
	return 0;
} 
