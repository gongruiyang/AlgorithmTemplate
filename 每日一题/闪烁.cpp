#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1 << 16;
int n;
long long m;
int p[N];	// ÿһ��״̬�ǵڼ����ߵ��� p[state] = steps 

int update(int state)
{
	int res = 0;	// ��һ��״̬ 
	for(int i= 0; i < n; i++)	// ö��ÿһλ 
	{
		int j = (i - 1 + n) % n;	// ǰ 1 λ
		// ���� i λ�͵� j λ������ȡ���� 
		int x = state >> i & 1, y = state >> j & 1;
		// ��ǰ��һλ�� x^y ���ƶ����� i λ�� 
		res |= (x ^ y) << i;
	}
	return res;
}
// 10����ת��Ϊ2���ƣ����ÿһλ 
void  print(int state)
{
	for(int i = 0; i < n; i++)
		cout << (state >> i & 1) << endl;	
}

int main()
{
	cin >> n >> m;
	
	// n ������״̬ѹ���� state �� 
	int state = 0;	 
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		state |= x << i; // ״̬ѹ�� 
	}
	
	memset(p, -1, sizeof p);
	p[state] = 0;	// ��¼��ʼ״̬ 
	for(int i = 1;; i ++)
	{
		state = update(state);	// �����һ��״̬ 
		if(i == m)	// ��� m �������� 
		{
			print(state);
			break;
		}
		else if(p[state] == -1) // ��ǰ״̬û�б���ʼ���� 
			p[state] = i;	
		else
		{
			// ���ֻ�
			int len = i - p[state];	// ������ 
			int rest = (m - i) % len; 	// ����Ҫ�߶��ٲ���
			while(rest --) state = update(state);	// ��ʣ�µĲ������� 
			print(state); 	// ��ӡ�� 
			break;
		}
	}

	return 0;
}

