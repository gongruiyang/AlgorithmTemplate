#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
int n, m;
char str[N];
ULL h[N];	// 用来存储 字符串前缀的哈希值 
ULL p[N]; 	// 用来存储 预处理出来的P的次方值

ULL get(int l, int r)
{
	return h[r] - h[l-1] * p[r - l + 1];
}

int main()
{
	cin >> n >> m >> str + 1;

	// 预处理p数组:中间出现溢出时会自动对 2^64 取模 
	p[0] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = p[i-1] * P;

	// 构建字符串前缀的哈希值数组 
	for(int i = 1; i <= n; i++)
		h[i] = h[i-1] * P + str[i]; 
	
	
	// 判断[l1, r1]和[l2, r2]两段字符串哈希值是否相同 
	// 两个串的哈希值相同则认为两个串相同，存在冲突情况，但是概率极小不考虑 
	for(int i = 0; i < m; i++)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1, r1) == get(l2, r2)) 
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
