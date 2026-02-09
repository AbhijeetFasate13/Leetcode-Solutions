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
    void inorder(vector<int>& tree, TreeNode* root) {
        if (!root)
            return;
        inorder(tree, root->left);
        tree.push_back(root->val);
        inorder(tree, root->right);
    }
    TreeNode* buildIncBST(const vector<int>& tree) {
        if (tree.empty())
            return nullptr;
        TreeNode* root = new TreeNode(tree[0]);
        for (int i = 1; i < tree.size(); i++) {
            insertNode(root, tree[i]);
        }
        return root;
    }
    void insertNode(TreeNode* root, const int& data) {
        if (root->val > data) {
            if (root->left) {
                insertNode(root->left, data);
            } else {
                root->left = new TreeNode(data);
            }
        } else {
            if (root->right) {
                insertNode(root->right, data);
            } else {
                root->right = new TreeNode(data);
            }
        }
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> tree;
        inorder(tree, root);
        TreeNode* incBST = buildIncBST(tree);
        return incBST;
    }
};