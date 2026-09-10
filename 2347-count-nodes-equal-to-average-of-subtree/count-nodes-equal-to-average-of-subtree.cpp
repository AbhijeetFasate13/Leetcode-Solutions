/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct info {
    int sum;
    int count;
};

class Solution {
    int ans = 0;

    info dfs(TreeNode* root) {
        if (!root)
            return {0, 0};

        info l = dfs(root->left);
        info r = dfs(root->right);

        int sum = root->val + l.sum + r.sum;
        int count = 1 + l.count + r.count;

        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};