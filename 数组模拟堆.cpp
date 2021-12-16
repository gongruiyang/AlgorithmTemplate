#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int h[N], ph[N], hp[N], cnt;
/*
	h[i] = x  	用于存储节点值 x 
	ph[i] = x 	用于指向第 i 个插入的元素 h[x] 在 h 数组中的下标 x 
	hp[i] = x	
	cnt  		用于控制 h 数组的下标，即当前堆一共有 cnt 个元素 
*/

// 将堆中的两个元素互换 
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
	int m = 0;	// 用于存储当前是第几次插入的 
	for(int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if(op == "I")	// 插入一个数x
		{
			int x;
			cin >> x; 
			cnt++, m++;
			ph[m] = cnt;	// 将 x 在 h 数组的下标 cnt 保存在 ph 数组的 m 处 
			hp[cnt] = m;	// 将 x 在 ph 数组的下标 m 保存在 hp 数组的 cnt 处 
			h[cnt] = x;		// 在 h 数组的 cnt 处插入值 x  
			up(cnt);
		}
		else if(op == "PM") // 输出当前集合中最小值
		{
			cout << h[1] << endl;
		} 
		else if(op == "DM") // 删除当前集合中的最小值
		{
		 	heap_swap(1, cnt);	// 将堆顶元素与最后一个元素交换 
		 	cnt --;	// 删除最后一个元素 
		 	down(1);
		}
		else if(op == "D") 	// 删除第 k 个插入的数
		{
			int k;
			cin >> k; 
			k = ph[k];	// 取出第k个插入的数在h数组中的下标 
			heap_swap(k, cnt);	// 交换第 k 个元素 和 最后一个元素 
			cnt--;	// 删除最后一个元素 
			up(k);
			down(k);
		}
		else if(op == "C") 	// 修改第K个插入的数为x 
		{
			int k, x;
			cin >> k >> x;
			k = ph[k];	// 取出第k个插入的数在h数组中的下标 
			h[k] = x;
			up(k);
			down(k);
		}
	}
	return 0;
} 
