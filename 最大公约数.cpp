#include <iostream>
using namespace std;

// ŷ������㷨 
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;	
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) <<endl;
	}
	
	return 0;
}
