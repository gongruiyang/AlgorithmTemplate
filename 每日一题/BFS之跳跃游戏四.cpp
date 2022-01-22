#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map> 
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6;
int dist[N];	// 记录到达某个位置的最小步数

int minJumps(vector<int>& arr) {
    // 从后向前 将所有等值的下标存入哈希表中 
    int n = arr.size();
    unordered_map<int, vector<int>> map;
    for(int i = n - 1; ~i; i--) map[arr[i]].push_back(i);

    // 单向BFS 
    memset(dist, INF, sizeof dist);
    queue<int> q;	// 存下标
    // 入队第一个点 
    q.push(0);
    dist[0] = 0;
    while(q.size()) 
    {
        auto t = q.front();
        q.pop();
        int step = dist[t];	// 获取当前步数 
        
        if(t == n - 1) 	// 如果当前到达终点 
            return step;
        // 将前面的点入队 
        if(t + 1 < n && dist[t + 1] == INF) 
        {
            q.push(t + 1);
            dist[t + 1] = step + 1;
        }
        // 将后面的点入队 
        if(t - 1 >= 0 && dist[t - 1] == INF) 
        {
            q.push(t - 1);
            dist[t - 1] = step + 1;
        }
        // 将与当前点所有等值的点入队 
        const auto& list = map[arr[t]];
        for(auto ne :list) 
        {
            if(dist[ne] == INF) 
            {
                q.push(ne);
                dist[ne] = step + 1;
            }
        }
        // 将当前所有等值的点从哈希表里面删除 
        map[arr[t]].clear(); //or map.erase(arr[t]);
    }
    return -1;
}

int main()
{
	vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
	cout <<  minJumps(arr) << endl;

	return 0;
}

