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
    void inorder(TreeNode*& prev, TreeNode* root, int& diff) {
        if (!root)
            return;
        inorder(prev, root->left, diff);
        if (prev)
            diff = min(abs(root->val - prev->val), diff);
        prev = root;
        inorder(prev, root->right, diff);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(prev, root, diff);
        return diff;
    }
};