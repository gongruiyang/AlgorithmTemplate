#include <iostream>
using namespace std;


typedef long long LL;
int qmi(int a, int k, int p)
{
	int res = 1;	// a^0 = 1 
	while(k)
	{
		if(k & 1) // k的二进制最低位是 1 
			res = (LL)res * a % p; 
		k >>= 1;
		// 相当于预处理 a 的幂数组 
		a = (LL)a * a % p; 
	}
	return res; 
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int a, k, p;
		cin >> a >> k >> p;	
		cout << qmi(a, k, p) << endl; 
	}
	
	return 0; 
}
