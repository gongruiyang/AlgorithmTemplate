#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map> 
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6;
int dist[N];	// ��¼����ĳ��λ�õ���С����

int minJumps(vector<int>& arr) {
    // �Ӻ���ǰ �����е�ֵ���±�����ϣ���� 
    int n = arr.size();
    unordered_map<int, vector<int>> map;
    for(int i = n - 1; ~i; i--) map[arr[i]].push_back(i);

    // ����BFS 
    memset(dist, INF, sizeof dist);
    queue<int> q;	// ���±�
    // ��ӵ�һ���� 
    q.push(0);
    dist[0] = 0;
    while(q.size()) 
    {
        auto t = q.front();
        q.pop();
        int step = dist[t];	// ��ȡ��ǰ���� 
        
        if(t == n - 1) 	// �����ǰ�����յ� 
            return step;
        // ��ǰ��ĵ���� 
        if(t + 1 < n && dist[t + 1] == INF) 
        {
            q.push(t + 1);
            dist[t + 1] = step + 1;
        }
        // ������ĵ���� 
        if(t - 1 >= 0 && dist[t - 1] == INF) 
        {
            q.push(t - 1);
            dist[t - 1] = step + 1;
        }
        // ���뵱ǰ�����е�ֵ�ĵ���� 
        const auto& list = map[arr[t]];
        for(auto ne :list) 
        {
            if(dist[ne] == INF) 
            {
                q.push(ne);
                dist[ne] = step + 1;
            }
        }
        // ����ǰ���е�ֵ�ĵ�ӹ�ϣ������ɾ�� 
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

