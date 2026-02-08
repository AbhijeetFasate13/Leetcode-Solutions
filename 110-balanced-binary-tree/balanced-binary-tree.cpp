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
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        int l = 0, r = 0;
        if (root->left)
            l = getHeight(root->left);
        if (l == -1)
            return -1;
        if (root->right)
            r = getHeight(root->right);
        if (r == -1)
            return -1;
        if (abs(l - r) > 1)
            return -1;

        return 1 + max(l, r);
    }

public:
    bool isBalanced(TreeNode* root) { return getHeight(root) != -1; }
};