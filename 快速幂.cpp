#include <iostream>
using namespace std;


typedef long long LL;
int qmi(int a, int k, int p)
{
	int res = 1;	// a^0 = 1 
	while(k)
	{
		if(k & 1) // k�Ķ��������λ�� 1 
			res = (LL)res * a % p; 
		k >>= 1;
		// �൱��Ԥ���� a �������� 
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
