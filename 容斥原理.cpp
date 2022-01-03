#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int M = 20;
int n, m;
int p[M];	// �� m ������ 


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> p[i];
	
	int res = 0;
	// i: [1, 2^m]
	for(int i = 1; i < 1 << m; i++)
	{
		int t = 1; // ���������ĳ˻� 
		int cnt = 0; // ��ǰѡ�����ж��ٸ�����
		for(int j = 0; j < m; j++)
			if(i >> j & 1)
			{
				cnt ++;
				if((LL)t * p[j] > n)
				{
					t = -1;
					break;	
				}	
				t *= p[j];
			}
		if(t != -1)
		{
			if(cnt % 2) res += n / t;
			else res -= n / t;
		}
	}
	
	cout << res << endl;

	return 0;
}
