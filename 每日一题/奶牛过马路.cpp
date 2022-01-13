#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#define x first 
#define y second
const int N = 1e5 + 10;
int n;
typedef pair<int, int> PII;
PII p[N];	// �� n �����ݶ� 
int prefixMax[N];	// ����ǰ׺���ֵ���� 
int suffixMin[N];	// �����׺��Сֵ���� 

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y;
	// ���� + �������� 
	sort(p + 1, p + n + 1);
	int i;
	for(i = 2, prefixMax[1] = p[1].y; i <= n; i++)
		prefixMax[i] = max(prefixMax[i-1], p[i].y);
	for(i = n - 1, suffixMin[n] = p[n].y; i >= 1; i--)
		suffixMin[i] = min(suffixMin[i+1], p[i].y);
	//  �жϵ�ǰ��� pb ��ǰ׺���ֵ pa ���׺��Сֵ pc �Ƿ񹹳� a <= b <= c �Ĺ�ϵ 
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int pa = prefixMax[i];
		int pb = p[i].y;
		int pc = suffixMin[i];
		if(pa <= pb && pb <= pc) res++;
	}
	cout << res << endl;
	
	return 0;
}

