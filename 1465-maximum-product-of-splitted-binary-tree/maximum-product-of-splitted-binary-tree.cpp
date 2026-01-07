class Solution {
    long long totalSum = 0;
    long long maxProductVal = 0;

    long long dfs(TreeNode* root) {
        if (!root)
            return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subtreeSum = leftSum + rightSum + root->val;
        maxProductVal =
            max(maxProductVal, subtreeSum * (totalSum - subtreeSum));

        return subtreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        maxProductVal = 0;
        dfs(root);

        return maxProductVal % 1000000007;
    }
};
