#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;
unordered_map<int, int> primes;	// �洢 <������, ����> 
LL get_primes_nums(int n)
{
	// ͳ���������ֽ���������������� 
	while(n--)
	{
		int x;
		cin >> x;
		// �������ֽ� 
		for(int i = 2; i <= x / i; i++)
			while(x % i == 0)
			{
				x /= i;
				primes[i] ++;
			}
		// �� x �����һ��������ʱ 
		if(x > 1) primes[x]++; 
	}
	// Լ������ = (a1 + 1)(a2 + 1)(a3 + 1)*****(ak + 1) 
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
