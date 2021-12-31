#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int primes[N], cnt;
int phi[N];
bool st[N];

LL get_eulers(int n)
{
	phi[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])	// 该数是质数 
		{
			primes[cnt++] = i;
			// 与质数 i 互质的数的个数为 1 ~ i-1 
			phi[i] = i - 1;
		}
		for(int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
			{
				// primes[j] 是 i 的质因子
				// 故 primes[j] * i 的质因子与 i 的质因子完全相同 
				phi[primes[j] * i] = phi[i] * primes[j];
				break;
			}
			// primes[j] 不是 i 的质因子
			// 故 primes[j] * i 的质因子比 i 的质因子多出来一个 primes[j]
			// phi[primes[j] * i] = phi[i] * primes[j] * (1 - 1 / primes[j])
			else phi[primes[j] * i] = phi[i] * (primes[j] - 1);
		}
	}
	
	LL res = 0;
	for(int i = 1; i <= n; i++) res += phi[i];
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << get_eulers(n) << endl;
	
	return 0;
}
