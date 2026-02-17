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
class Solution {
    int dfsSum(TreeNode* root, int& maxm) {
        if (!root)
            return 0;
        int l = max(0, dfsSum(root->left, maxm));
        int r = max(0, dfsSum(root->right, maxm));
        maxm = max(maxm, root->val + l + r);
        return root->val + max(l, r);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxm = INT_MIN;
        dfsSum(root, maxm);
        return maxm;
    }
};