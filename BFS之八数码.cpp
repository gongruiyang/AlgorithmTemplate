#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

string start; 				// �洢��ʼ�ַ���
string end = "12345678x";	// �����ַ���
queue<string> q;			// �м�״̬ 
unordered_map<string, int> d;	// �����м�״̬����Ľ������� 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; 

int bfs()
{
	q.push(start);
	d[start] = 0;
	while(!q.empty())
	{
		string head = q.front();
		q.pop();
		
		int distance = d[head];	// ��ȡ��ǰ�� string �ľ��� 
		if(head == ::end) return distance;
		
		// ��ȡ 'x' �Ķ�ά���� (x, y) 
		int pos = head.find('x');
		int x = pos / 3, y = pos % 3;
		for(int i = 0; i < 4; i++)
		{
			// ��� 'x' ��Χ�ĸ���Ķ�ά���� (a, b) 
			int a = x + dx[i], b = y + dy[i];
			// �ж��Ƿ�Ϸ� 
			if(a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				// ���� 'x' �� (a, b)����ʱhead�е��ַ�λ���Ѿ������˽��� 
				swap(head[pos], head[a * 3 + b]);
				// �ж� hash�� ���Ƿ��¼���м�״̬ 
				if(!d.count(head))
				{ 
					d[head] = distance + 1;
					q.push(head);
				}
				// �ָ��ֳ� 
				swap(head[pos], head[a * 3 + b]);
			}
		}
	}
	return -1;
}

int main ()
{
	// 2  3  4  1  5  x  7  6  8
	for(int i = 0; i < 9; i++)
	{
		char c;
		cin >> c;
		start += c;	
	}	
	// 19
	cout << bfs() << endl;
	
	return 0;
} 
