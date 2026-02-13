class Solution {
public:
    int sumNumbers(TreeNode* root, int currSum = 0) {
        if (!root)
            return 0;
        currSum = currSum * 10 + root->val;
        if (!root->left && !root->right)
            return currSum;

        return sumNumbers(root->left, currSum) +
               sumNumbers(root->right, currSum);
    }
};
