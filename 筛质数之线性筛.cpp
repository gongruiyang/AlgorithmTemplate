#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int primes[N];	// �洢���� 
bool st[N];
int ans;

void get_primes(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i]) 
			primes[cnt ++] = i;
		for(int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0) // ���� j <= cnt 
				break;	
		}
	} 
}

int main()
{
	int n;
	cin >> n;
	get_primes(n);
	cout << ans << endl;
	return 0;
}
