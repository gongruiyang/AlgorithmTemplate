#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* phead;
    Solution(ListNode* head) {
        phead = head;
    }
    
    int getRandom() 
    {
		int ans = 0, i = 0;
		for(auto cur = phead; cur; cur = cur->next, i ++)
			if(rand() % i == 0) ans = cur->val;
		return ans; 
    }
};

int main()
{


	return 0;
}

