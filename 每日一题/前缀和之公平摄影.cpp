#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;
typedef pair<int,int> PII;
#define x first
#define b second
PII p[N];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int xi;
		char bi;
		cin >> xi >> bi;
		p[i].x = xi;
		if(bi == 'H') p[i].b = 1;
		else p[i].b = -1;
	}
	
	sort(p, p + n);
	// �𰸿��ܵ������
	// 		1. ���� 1 �� -1
	// 		2. ĳ���������� ��ȸ����� 1 �� -1 
	unordered_map<int, int> hash;
	int res = 0, sum = 0, last;
	for(int i = 0; i < n; i ++)
	{
		// [1, si) 
		if(!hash.count(sum))
			hash[sum] = p[i].x;
		// [1, si]
		sum += p[i].y;
		// �� sum �Ѿ����ֹ������µȳ� 1 �� -1 �Ĵ����� 
		if(hash.count(sum))
			res = max(res, p[i].x - hash[sum]);
		
		// �������� 1 �� -1 ����� 
		if(i == 1 || p[i].y != p[i-1].y) 
			last = p[i].x;
		// �������� 1 �� -1 �Ŀ��ܴ����� 
		res = max(res, p[i].x - last);
	}
	
	cout << res << endl;
	
	return 0;
}

