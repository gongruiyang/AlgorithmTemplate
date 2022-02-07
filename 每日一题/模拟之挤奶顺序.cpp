#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int n, m, k;
int order[N]; 				// �洢 m ͷţ�γɵ����ײ� 
int cow[N], pos[N];			// �洢 k ͷţ�� ��� �� �ض�����λ�� 
bool st_cow[N], st_pos[N];	// �洢 n ͷţ�� ��� �� ����λ�� �Ƿ��Ѿ���ռ�� 
int c2p[N];					// �洢 n ͷţ�� ��� �� ����λ�� 

bool check(int idx)
{
	// ��ʼ���������� 
	memset(st_cow, false, sizeof st_cow);
	memset(st_pos, false, sizeof st_pos);
	memset(c2p, 0, sizeof c2p);
	
	// �ж� k ����ţ�� �ض�λ�� �Ƿ����Ҫ�� : cow \ pos 
	for(int i = 1; i <= idx; i ++)
	{
		int cur_cow = cow[i], cur_pos = pos[i];
		if(st_cow[cur_cow] && c2p[cur_cow] == cur_pos) //  
			continue;
		if(st_cow[cur_cow] || st_pos[cur_pos])  // ��ǰ��Ż��߼���λ���Ѿ���֮ǰţռ�� 
			return false;
		// ��ţ�����Ӧλ�ò��޸�ռ������ 
		c2p[cur_cow] = cur_pos; 
		st_cow[cur_cow] = st_pos[cur_pos] = true;
	}
	
	// �ж� m ����ţ�� ���ײ� �Ƿ����Ҫ�� : order 
	int cur_pos = 1;
	for(int i = 1; i <= m; i ++)
	{
		int cur_cow = order[i];
		// ��ǰ��ţ�Ѿ���������˳�� 
		if(st_cow[cur_cow])
		{
			// cur_pos�����ţ�����ܳ��ֵ�λ�ã� c2p[cur_cow]����֮ǰ�źõ�λ�� 
			if(cur_pos > c2p[cur_cow])  // ����ì�� 
				return false;
			cur_pos = c2p[cur_cow]; // ��ȡ��ǰ��ţ��˳����� cur_pos 
			continue;
		}
		// ��ǰ��ţ��δ�����ż���˳����Ҫ�ҵ�һ������λ��
		while(st_pos[cur_pos])
		{
			cur_pos++; 
			if(cur_pos > n) // �����߽� 
				return false;
		} 
		// ����c2p���飺�� cur_cow ���� cur_pos ������ 
		st_pos[cur_pos] = true;
		c2p[cur_cow] = cur_pos;
	}
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) cin >> order[i];
	for(int i = 1; i <= k; i ++) cin >> cow[i] >> pos[i];
	
	int idx = k + 1;
	for(int i = 1; i <= n; i ++)
	{
		cow[idx] = 1, pos[idx] = i;	// ������ţ 1 λ�ڵ� i λ
		if(check(idx))
		{
			cout << i << endl;
			break;	
		} 
	}

	return 0;
}

