#include <iostream>
using namespace std;

const int N = 1e6 + 10;
bool st[N];	// ��־ idx �Ƿ�ɾ�� 
int ans; 

void get_primes(int n)
{
	// �� [2, n] �н���Ѱ�� 
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])	// ����ǰ��û�б�ɾ������ǰ��Ϊ���� 
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
