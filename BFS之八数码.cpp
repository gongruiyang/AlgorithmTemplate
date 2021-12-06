#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

string start; 				// 存储初始字符串
string end = "12345678x";	// 结束字符串
queue<string> q;			// 中间状态 
unordered_map<string, int> d;	// 到达中间状态所需的交换次数 
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
		
		int distance = d[head];	// 获取当前的 string 的距离 
		if(head == ::end) return distance;
		
		// 获取 'x' 的二维坐标 (x, y) 
		int pos = head.find('x');
		int x = pos / 3, y = pos % 3;
		for(int i = 0; i < 4; i++)
		{
			// 获得 'x' 周围四个点的二维坐标 (a, b) 
			int a = x + dx[i], b = y + dy[i];
			// 判断是否合法 
			if(a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				// 交换 'x' 与 (a, b)，此时head中的字符位置已经发生了交换 
				swap(head[pos], head[a * 3 + b]);
				// 判断 hash表 中是否记录该中间状态 
				if(!d.count(head))
				{ 
					d[head] = distance + 1;
					q.push(head);
				}
				// 恢复现场 
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
