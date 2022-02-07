#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> 
using namespace std;

typedef pair<int, int> PII;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        // <counter : alph>
        priority_queue<PII> heap;
        if(a) heap.push({a, 0});    // 0 -> 'a'
        if(b) heap.push({b, 1});    // 1 -> 'b'
        if(c) heap.push({c, 2});    // 2 -> 'c'
        
        string ans;
        while(heap.size())
        {
        	auto t = heap.top();
        	heap.pop();
			
			// ans : ****aa / ****bb / ****cc
        	if(ans.size() >= 2 &&
				t.second + 'a' == ans[ans.size() - 1] &&
				t.second + 'a' == ans[ans.size() - 2])
        	{
        		// t.second �Ѿ��� ans ĩβ�������� 
        		if(heap.size() == 0) break;
        		
        		// ȡ�� tt �� ans ������ һ���ַ� 
				auto tt = heap.top();
				heap.pop();
				ans += ('a' + tt.second);
				tt.first -= 1;
				
				// �� t �� tt ������� 
				if(tt.first)
					heap.push(tt);
				heap.push(t);
			}
			else	// ���Խ� t ���ӵ� ans �� 
			{
				ans += ('a' + t.second);
				t.first -= 1;
				
                // �� t �������
				if(t.first) 
					heap.push(t);
			}
		}
        
        return ans;
    }
};
int main()
{


	return 0;
}

