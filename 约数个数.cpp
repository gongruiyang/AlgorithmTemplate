#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;
unordered_map<int, int> primes;	// 存储 <质因子, 次数> 
LL get_primes_nums(int n)
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
	// 约数个数 = (a1 + 1)(a2 + 1)(a3 + 1)*****(ak + 1) 
	LL res = 1;
	for(auto prime : primes)
		res = res * (prime.second + 1) % mod;
	return res;
} 

int main()
{
	int n;
	cin >> n;
	cout << get_primes_nums(n) << endl;
	
	return 0;
}
