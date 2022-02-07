#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	if(!root) return true;
		auto res = dfs(root);
		return res[0];
    }
    
    // 0:0表示有问题 1:MIN 2:MAX 
    vector<int> dfs(TreeNode* root)
    {
    	vector<int> res({1, root->val, root->val});
    	if(root->left)
    	{
    		auto t = dfs(root->left);
    		if(!t[0] || t[2] >= root->val) 
				res[0] = 0;
    		res[1] = min(res[1], t[1]);
    		res[2] = max(res[2], t[2]);
		}
    	if(root->right)
    	{
    		auto t = dfs(root->right);
    		if(!t[0] || t[1] <= root->val) 
				res[0] = 0;
    		res[1] = min(res[1], t[1]);
    		res[2] = max(res[2], t[2]);
		}
		return res;
	}
};

int main()
{


	return 0;
}

