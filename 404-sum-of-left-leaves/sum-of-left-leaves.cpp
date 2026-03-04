class Solution {
public:
    int helper(TreeNode* root, bool isLeft) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            if (isLeft)
                return root->val;
            else
                return 0;
        }

        return helper(root->left, true) +
               helper(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};