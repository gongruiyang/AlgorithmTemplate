#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) 
	{
		vector<vector<int>> h(n);	// ��ӱ� 
		vector<int> d(n); 	// ���
        // ��������ͼ��ͳ��ÿ��������
		for(auto e : edges)
		{
			int a = e[0], b = e[1];
			h[a].push_back(b);
			d[b] ++;
		}
	
		// topsort (��������)
		queue<int> q;
		// ���������Ϊ 0 �ĵ���� 
		for(int i = 0; i < n; i ++)
			if(d[i] == 0) q.push(i);
		
		int count = q.size();   // ����ͳ���������򵽵ĵ�ĸ���
		while(q.size())
		{
			int t = q.front();
			q.pop();
			
			for(auto i : h[t])
			{
				d[i] --;    // ɾ�� t->i ֮��ı�
				if(d[i] == 0)   // �� i �����Ϊ 0
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

