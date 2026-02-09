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
    void inorderTraverse(TreeNode* root, vector<int>& tree) {
        if (!root)
            return;
        if (root->left)
            inorderTraverse(root->left, tree);
        tree.push_back(root->val);
        if (root->right)
            inorderTraverse(root->right, tree);
    }
    TreeNode* buildBalancedTree(vector<int>& tree, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(tree[mid]);
        root->left = buildBalancedTree(tree, left, mid - 1);
        root->right = buildBalancedTree(tree, mid + 1, right);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;
        inorderTraverse(root, tree);
        TreeNode* balancedTree = buildBalancedTree(tree, 0, tree.size() - 1);
        return balancedTree;
    }
};