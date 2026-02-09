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
    bool isValid(TreeNode* root, TreeNode*& prev) {
        if (!root)
            return true;
        bool l = isValid(root->left, prev);
        bool mid = true;
        if (prev and prev->val >= root->val)
            mid = false;
        prev = root;
        bool r = isValid(root->right, prev);
        return l and r and mid;
    }

public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValid(root, prev);
    }
};