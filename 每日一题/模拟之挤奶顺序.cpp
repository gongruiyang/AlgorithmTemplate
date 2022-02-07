#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110;
int n, m, k;
int order[N]; 				// 存储 m 头牛形成的社会阶层 
int cow[N], pos[N];			// 存储 k 头牛的 编号 和 特定挤奶位置 
bool st_cow[N], st_pos[N];	// 存储 n 头牛的 编号 和 挤奶位置 是否已经被占领 
int c2p[N];					// 存储 n 头牛的 编号 和 挤奶位置 

bool check(int idx)
{
	// 初始化判重数组 
	memset(st_cow, false, sizeof st_cow);
	memset(st_pos, false, sizeof st_pos);
	memset(c2p, 0, sizeof c2p);
	
	// 判断 k 个奶牛的 特定位置 是否符合要求 : cow \ pos 
	for(int i = 1; i <= idx; i ++)
	{
		int cur_cow = cow[i], cur_pos = pos[i];
		if(st_cow[cur_cow] && c2p[cur_cow] == cur_pos) //  
			continue;
		if(st_cow[cur_cow] || st_pos[cur_pos])  // 当前序号或者挤奶位置已经被之前牛占了 
			return false;
		// 将牛放入对应位置并修改占领数组 
		c2p[cur_cow] = cur_pos; 
		st_cow[cur_cow] = st_pos[cur_pos] = true;
	}
	
	// 判断 m 个奶牛的 社会阶层 是否符合要求 : order 
	int cur_pos = 1;
	for(int i = 1; i <= m; i ++)
	{
		int cur_cow = order[i];
		// 当前奶牛已经被安排了顺序 
		if(st_cow[cur_cow])
		{
			// cur_pos代表该牛最早能出现的位置， c2p[cur_cow]代表之前排好的位置 
			if(cur_pos > c2p[cur_cow])  // 出现矛盾 
				return false;
			cur_pos = c2p[cur_cow]; // 获取当前奶牛的顺序更新 cur_pos 
			continue;
		}
		// 当前奶牛还未被安排挤奶顺序，需要找到一个空闲位置
		while(st_pos[cur_pos])
		{
			cur_pos++; 
			if(cur_pos > n) // 超出边界 
				return false;
		} 
		// 更新c2p数组：将 cur_cow 放在 cur_pos 处挤奶 
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
		cow[idx] = 1, pos[idx] = i;	// 假设奶牛 1 位于第 i 位
		if(check(idx))
		{
			cout << i << endl;
			break;	
		} 
	}

	return 0;
}

