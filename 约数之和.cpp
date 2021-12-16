#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;
typedef long long LL;
unordered_map<int, int> primes;	// �洢 <������, ����> 
LL get_primes_sum(int n)
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
	// sum = (p1^0 + p1^1 + .... + p1^a1)(p2^0 + p2^1 + .... + p2^a1) ... (pk^0 + pk^1 + .... + pk^a1)
	LL res = 1;
	for(auto prime : primes)
	{
		// �� d 
		LL a = prime.first;
		LL b = prime.second;
		LL d = 1;
		while(b--)
		{
			d = (d * a + 1) % mod;
		}
		// �� d �۳��� res 
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
