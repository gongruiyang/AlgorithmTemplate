#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1 << 16;
int n;
long long m;
int p[N];	// 每一个状态是第几步走到的 p[state] = steps 

int update(int state)
{
	int res = 0;	// 下一个状态 
	for(int i= 0; i < n; i++)	// 枚举每一位 
	{
		int j = (i - 1 + n) % n;	// 前 1 位
		// 将第 i 位和第 j 位的数字取出来 
		int x = state >> i & 1, y = state >> j & 1;
		// 当前这一位是 x^y 再移动到第 i 位上 
		res |= (x ^ y) << i;
	}
	return res;
}
// 10进制转换为2进制，输出每一位 
void  print(int state)
{
	for(int i = 0; i < n; i++)
		cout << (state >> i & 1) << endl;	
}

int main()
{
	cin >> n >> m;
	
	// n 个灯泡状态压缩至 state 中 
	int state = 0;	 
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		state |= x << i; // 状态压缩 
	}
	
	memset(p, -1, sizeof p);
	p[state] = 0;	// 记录初始状态 
	for(int i = 1;; i ++)
	{
		state = update(state);	// 获得下一个状态 
		if(i == m)	// 如果 m 步走完了 
		{
			print(state);
			break;
		}
		else if(p[state] == -1) // 当前状态没有被初始化过 
			p[state] = i;	
		else
		{
			// 发现环
			int len = i - p[state];	// 环长度 
			int rest = (m - i) % len; 	// 还需要走多少步数
			while(rest --) state = update(state);	// 把剩下的步数走完 
			print(state); 	// 打印答案 
			break;
		}
	}

	return 0;
}

