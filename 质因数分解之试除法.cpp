#include <iostream>
using namespace std;

void divide(int n)
{
	for(int i = 2; i <= n / i; i++)
		if(n % i == 0)	 
		{
			// ��ʱiһ�������������������i�Ĵη�ֵs 
			int s = 0;
			while(n % i == 0)
			{
				s ++;
				n /= i;
			} 
			cout << i << " " << s << endl;
		}
	// ��ʱ n ������һ������ 
	if(n > 1) cout << n << " " << 1 << endl;
	cout << endl;
} 

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		divide(x);
	}
	
	return 0;
}
