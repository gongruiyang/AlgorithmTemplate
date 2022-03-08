#include "../header.h"
#include "../Tree.h"
/**
 *  538. 把二叉搜索树转换为累加树
 *  tag : 右 -> 根 -> 左 遍历
 */
class LC538 {
public:
    int res = 0;
    void dfs(TreeNode*& root) {
        if(root == nullptr) return ;
        dfs(root->right);
        res += root->val;
        root->val = res;
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};