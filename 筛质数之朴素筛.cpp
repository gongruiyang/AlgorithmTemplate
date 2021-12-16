#include <iostream>
using namespace std;

const int N = 1e6 + 10;
bool st[N];	// 标志 idx 是否被删除 
int ans; 

void get_primes(int n)
{
	// 在 [2, n] 中进行寻找 
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])	// 若当前数没有被删除，则当前数为质数 
			ans++
		for(int j = i*2; j <= n; j += i)
			st[j] = true;
	}
}

int main()
{
	int n;
	cin >> n;
	get_primes(n);
	cout << ans << endl;
} 
