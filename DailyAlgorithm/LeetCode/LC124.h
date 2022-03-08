#include "../header.h"
#include "../Tree.h"

/**
 *  124. 二叉树中的最大路径和
 *  tag : 最近公共祖先
 */
class LC124 {
public:
    int ans;

    int dfs(TreeNode *u) {
        if(u == nullptr) return 0;
        // 左右路径可能是负值
        int left = max(dfs(u->left), 0), right = max(0, dfs(u->right));
        // 使用 u 将左右两条路线连接起来获得一个可能的答案
        ans = max(ans, u->val + left + right);
        // 以 u 为路径端点向下延伸的最长路径长度
        return u->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};