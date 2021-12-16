#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;
unordered_map<int, int> primes;	// 存储 <质因子, 幂数> 
LL get_primes_sum(int n)
{
	// 统计所有数分解的质因数及其幂数 
	while(n--)
	{
		int x;
		cin >> x;
		// 质因数分解 
		for(int i = 2; i <= x / i; i++)
			while(x % i == 0)
			{
				x /= i;
				primes[i] ++;
			}
		// 当 x 最后是一个大质数时 
		if(x > 1) primes[x]++; 
	}
	// sum = (p1^0 + p1^1 + .... + p1^a1)(p2^0 + p2^1 + .... + p2^a1) ... (pk^0 + pk^1 + .... + pk^a1)
	LL res = 1;
	for(auto prime : primes)
	{
		// 求 d 
		LL a = prime.first;
		LL b = prime.second;
		LL d = 1;
		while(b--)
		{
			d = (d * a + 1) % mod;
		}
		// 将 d 累乘入 res 
		res = res * d % mod;
	}
	return res;
} 

int main()
{
	int n;
	cin >> n;
	cout << get_primes_sum(n) << endl;
	
	return 0;
}
