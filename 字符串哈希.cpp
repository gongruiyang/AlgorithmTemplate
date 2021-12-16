#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
int n, m;
char str[N];
ULL h[N];	// �����洢 �ַ���ǰ׺�Ĺ�ϣֵ 
ULL p[N]; 	// �����洢 Ԥ���������P�Ĵη�ֵ

ULL get(int l, int r)
{
	return h[r] - h[l-1] * p[r - l + 1];
}

int main()
{
	cin >> n >> m >> str + 1;

	// Ԥ����p����:�м�������ʱ���Զ��� 2^64 ȡģ 
	p[0] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = p[i-1] * P;

	// �����ַ���ǰ׺�Ĺ�ϣֵ���� 
	for(int i = 1; i <= n; i++)
		h[i] = h[i-1] * P + str[i]; 
	
	
	// �ж�[l1, r1]��[l2, r2]�����ַ�����ϣֵ�Ƿ���ͬ 
	// �������Ĺ�ϣֵ��ͬ����Ϊ��������ͬ�����ڳ�ͻ��������Ǹ��ʼ�С������ 
	for(int i = 0; i < m; i++)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1, r1) == get(l2, r2)) 
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
