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

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> tree;
        inorder(tree, root);
        int l = 0, r = tree.size() - 1;
        int sum;
        while (l < r) {
            sum = tree[l] + tree[r];
            if (sum < k) {
                l++;
            } else if (sum > k) {
                r--;
            } else {
                return true;
            }
        }
        return false;
    }
};