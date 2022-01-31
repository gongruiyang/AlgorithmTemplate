#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) 
	{
		vector<vector<int>> h(n);	// 领接表 
		vector<int> d(n); 	// 入度
        // 构造有向图和统计每个点的入队
		for(auto e : edges)
		{
			int a = e[0], b = e[1];
			h[a].push_back(b);
			d[b] ++;
		}
	
		// topsort (拓扑排序)
		queue<int> q;
		// 将所有入度为 0 的点入队 
		for(int i = 0; i < n; i ++)
			if(d[i] == 0) q.push(i);
		
		int count = q.size();   // 用于统计拓扑排序到的点的个数
		while(q.size())
		{
			int t = q.front();
			q.pop();
			
			for(auto i : h[t])
			{
				d[i] --;    // 删除 t->i 之间的边
				if(d[i] == 0)   // 若 i 的入度为 0
				{
					q.push(i);
					count ++;
				}
			}
		} 
		return count == n;
    }
};
int main()
{


	return 0;
}

