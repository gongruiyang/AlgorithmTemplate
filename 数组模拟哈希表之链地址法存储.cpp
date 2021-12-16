#include <iostream>
#include <cstring>
using namespace std;

// h(x) = x mod y  ���� y Ҫȡ����2������������Զ������ 
const int N = 1e5 + 10, Y = 1e5 + 3;
int h[N], e[N], ne[N], idx;	// ��ϣ�� 

void insert(int x)
{
	int hash = (x % Y + Y) % Y;		// ��ֹx�Ǹ���
	// ������������ 
	e[idx] = x;
	ne[idx] = h[hash];
	h[hash] = idx++;
}
string find(int x)
{
	int hash = (x % Y + Y) % Y;		// ��ֹx�Ǹ���
	// �������������
	for(int i = h[hash]; i != -1; i = ne[i])
	{
		if(e[i] == x)
			return "Yes";
	} 
	return "No";
}

int main()
{
	int n;
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 0; i < n; i++)
	{
		char op;
		int x;
		cin >> op >> x;
		if(op == 'I')	// ����һ����x 
		{
			insert(t);
		}
		else if(op == 'Q')	// ѯ��x�Ƿ��ڼ����г��ֹ� 
		{
			cout << find(x) << endl;
		}
	}	
	
	return 0;
} 
