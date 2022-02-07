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
	vector<TreeNode*> dfs(int le, int ri)
	{
		if(le > ri) return {NULL};
		
		vector<TreeNode*> res;
		for(int i = le; i <= ri; i ++)	// ö�ٸ���� 
		{
			auto left = dfs(le, i - 1), right = dfs(i + 1, ri);

			// �˷�ԭ��
			for(auto l : left)
				for(auto r : right)
				{
					auto root = new TreeNode(i);
					root->left = l, root->right = r;
					res.push_back(root);
				}
		}

		return res;		
	}
    vector<TreeNode*> generateTrees(int n) 
	{
		return dfs(1, n);
    }
};
int main()
{


	return 0;
}

