#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110, INF = 1e8;
int e[N], ne[N], d[N], n; // d ��ʾ��� 
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> e[i];
	e[0] = -INF, e[n+1] = INF;
	sort(e + 1, e + 1 + n);
	
	// ���� ne �� d ���� 
	for(int i = 1; i <= n; i ++)
		if(e[i] - e[i-1] <= e[i + 1] - e[i])	// �ұ� <= ��� 
		{
			ne[i] = i - 1;	// i ָ�� i-1 
			d[i - 1] ++;	// i-1 ��� +1 
		}
		else
		{
			ne[i] = i + 1;	// i ָ�� i+1
			d[i + 1] ++;	// i+1 ��� +1 
		}
	
	int res = 0;
	for(int i = 1; i <= n ; i ++)
		if(d[i] == 0) 	// �õ�����ͨ�����ʼ�� 
			res += 2;
		else if(ne[ne[i]] == i && d[i] == 1 && d[ne[i]] == 1) // �õ��ڻ����Ҳ������� 
			res += 1; 
		
	cout << res / 2 << endl; 
		 
	return 0;
}

