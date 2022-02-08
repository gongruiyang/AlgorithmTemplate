#include "../header.h"
#include "../Tree.h"

/**
 *  337. 打家劫舍 III
 *  tag : 树形DP
 */
class LC337 {
public:
    int rob(TreeNode* root) {
        auto f = dfs(root);
        return max(f[0], f[1]);
    }
    vector<int> dfs(TreeNode* u){
        if(u == nullptr) return {0, 0};

        auto x = dfs(u->left);
        auto y = dfs(u->right);

        // 选择
        auto notchoose = max(x[0], x[1]) + max(y[0], y[1]);
        auto choose = x[0] + y[0] + u->val;
        return {notchoose, choose};
    }
};
