#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
	if(n <= 1) return false;
	/*
		i * i <= n ���ڵ����⣺ �� i �Ƚϴ�ʱ��
					�ᵼ�� i*i ��������������ж� 
		i <= sqrt(n) ���ڵ����⣺ sqrt����ִ�к��� 
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
