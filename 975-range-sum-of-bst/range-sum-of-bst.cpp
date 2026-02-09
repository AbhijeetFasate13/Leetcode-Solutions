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
    void inorderTraverse(int& sum, const int& low, const int& high,
                         TreeNode* root) {
        if (!root)
            return;
        inorderTraverse(sum, low, high, root->left);
        if (root->val >= low and root->val <= high)
            sum += root->val;
        inorderTraverse(sum, low, high, root->right);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorderTraverse(sum, low, high, root);
        return sum;
    }
};