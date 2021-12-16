#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
	if(n <= 1) return false;
	/*
		i * i <= n 存在的问题： 当 i 比较大时，
					会导致 i*i 溢出，产生错误判断 
		i <= sqrt(n) 存在的问题： sqrt函数执行很慢 
	*/ 
	for(int i = 2; i <= n / i; i++)
		if(n % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		cout << (is_prime(x) ? "Yes" : "No") << endl; 
	}
	
	return 0;	
} 
