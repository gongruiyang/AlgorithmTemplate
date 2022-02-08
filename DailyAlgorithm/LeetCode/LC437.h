#include "../header.h"
#include "../Tree.h"

/**
 *  437. 路径总和 III
 *  tag : 前缀和 / dfs
 */
class LC437 {
public:
    unordered_map<int, int> cnt;
    int res = 0;

    // cur 为当前维护的前缀和
    void dfs(TreeNode *root, int target, int cur) {
        if(root == nullptr) return ;

        cur += root->val;
        res += cnt[cur - target];

        cnt[cur] ++;
        dfs(root->left, target, cur);
        dfs(root->right, target, cur);
        cnt[cur] --;
    }

    int pathSum(TreeNode* root, int target) {
        cnt[0]++;
        dfs(root, target, 0);
        return res;
    }
};
