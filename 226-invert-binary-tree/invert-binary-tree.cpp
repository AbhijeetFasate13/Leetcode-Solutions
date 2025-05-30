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
    void invert(TreeNode* root) {
        if (!root)
            return;
        if (root->left and root->right) {
            swap(root->left, root->right);
        } else if (root->left) {
            root->right = root->left;
            root->left = NULL;
        } else {
            root->left = root->right;
            root->right = NULL;
        }
        invert(root->left);
        invert(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};