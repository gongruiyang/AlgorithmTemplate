#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int h[N], ph[N], hp[N], cnt;
/*
	h[i] = x  	���ڴ洢�ڵ�ֵ x 
	ph[i] = x 	����ָ��� i �������Ԫ�� h[x] �� h �����е��±� x 
	hp[i] = x	
	cnt  		���ڿ��� h ������±꣬����ǰ��һ���� cnt ��Ԫ�� 
*/

// �����е�����Ԫ�ػ��� 
void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u)
{
	int t = u;
	if(u*2 <= cnt && h[u*2] < h[t]) t = u*2;
	if(u*2+1 <= cnt && h[u*2+1] < h[t]) t = u*2+1;
	if(u != t)
	{
		heap_swap(t, u);
		down(t);
	}
}

void up(int u)
{
	while(u/2 && h[u] < h[u/2])
	{
		heap_swap(u, u/2);
		u >>= 1;
	}
}

int main()
{
	int n;
	cin >> n;
	int m = 0;	// ���ڴ洢��ǰ�ǵڼ��β���� 
	for(int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if(op == "I")	// ����һ����x
		{
			int x;
			cin >> x; 
			cnt++, m++;
			ph[m] = cnt;	// �� x �� h ������±� cnt ������ ph ����� m �� 
			hp[cnt] = m;	// �� x �� ph ������±� m ������ hp ����� cnt �� 
			h[cnt] = x;		// �� h ����� cnt ������ֵ x  
			up(cnt);
		}
		else if(op == "PM") // �����ǰ��������Сֵ
		{
			cout << h[1] << endl;
		} 
		else if(op == "DM") // ɾ����ǰ�����е���Сֵ
		{
		 	heap_swap(1, cnt);	// ���Ѷ�Ԫ�������һ��Ԫ�ؽ��� 
		 	cnt --;	// ɾ�����һ��Ԫ�� 
		 	down(1);
		}
		else if(op == "D") 	// ɾ���� k ���������
		{
			int k;
			cin >> k; 
			k = ph[k];	// ȡ����k�����������h�����е��±� 
			heap_swap(k, cnt);	// ������ k ��Ԫ�� �� ���һ��Ԫ�� 
			cnt--;	// ɾ�����һ��Ԫ�� 
			up(k);
			down(k);
		}
		else if(op == "C") 	// �޸ĵ�K���������Ϊx 
		{
			int k, x;
			cin >> k >> x;
			k = ph[k];	// ȡ����k�����������h�����е��±� 
			h[k] = x;
			up(k);
			down(k);
		}
	}
	return 0;
} 
