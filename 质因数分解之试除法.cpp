#include <iostream>
using namespace std;

void divide(int n)
{
	for(int i = 2; i <= n / i; i++)
		if(n % i == 0)	 
		{
			// 此时i一定是质数，求出该质数i的次方值s 
			int s = 0;
			while(n % i == 0)
			{
				s ++;
				n /= i;
			} 
			cout << i << " " << s << endl;
		}
	// 此时 n 可能是一个质数 
	if(n > 1) cout << n << " " << 1 << endl;
	cout << endl;
} 

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		divide(x);
	}
	
	return 0;
}
