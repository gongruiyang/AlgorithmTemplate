#include <iostream>
#include <cstring>
using namespace std;

// h(x) = x mod y  其中 y 要取距离2的整数次幂最远的质数 
const int N = 1e5 + 10, Y = 1e5 + 3;
int h[N], e[N], ne[N], idx;	// 哈希表 

void insert(int x)
{
	int hash = (x % Y + Y) % Y;		// 防止x是负数
	// 单链表插入操作 
	e[idx] = x;
	ne[idx] = h[hash];
	h[hash] = idx++;
}
string find(int x)
{
	int hash = (x % Y + Y) % Y;		// 防止x是负数
	// 单链表遍历操作
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
		if(op == 'I')	// 插入一个数x 
		{
			insert(t);
		}
		else if(op == 'Q')	// 询问x是否在集合中出现过 
		{
			cout << find(x) << endl;
		}
	}	
	
	return 0;
} 
