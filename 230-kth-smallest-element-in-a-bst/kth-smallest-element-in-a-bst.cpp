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
    int inorder(TreeNode* root, int& k) {
        // the subtree has lesser nodes than k
        if (!root)
            return -1;

        int left = inorder(root->left, k);
        // ans in left if we get anything apart from -1
        if (left != -1)
            return left;
        k--;
        if (!k) {
            return root->val;
        }
        // since not in left it has to be in right;
        return inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) { return inorder(root, k); }
};