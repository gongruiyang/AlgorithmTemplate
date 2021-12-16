#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 10, Y = 2e5 + 3, INF = 0x3f3f3f3f;
int h[N];

void insert(int x)
{
	int pos = (x % Y + Y) % Y;
	// Ñ°ÕÒ¿ÓÎ» 
	while(h[pos] != INF)
	{
		pos++;
		if(pos == N) 	// ÅÐ¶ÏÊÇ·ñ×ßµ½µ× 
			pos = 0;
	}
	h[pos] = x; 
}

string find(int x)
{
	int pos = (x % Y + Y) % Y;
	int stop = pos;
	while(h[pos] != x && h[pos] != INF)
	{
		pos ++;
		if(pos == N) 
			pos = 0;
		if(pos == stop)
			return "No";
	}
	return "Yes";
}

int main()
{
	int n;
	cin >> n;
	memset(h, INF, sizeof h);
	for(int i = 0; i < n; i++)
	{
		char op;
		int x;
		cin >> op >> x;
		if(op == 'I')
		{
			insert(x);
		}
		else if(op == 'Q')
		{
			cout << find(x) << endl;
		}
	}
	
	return 0;	
} 
