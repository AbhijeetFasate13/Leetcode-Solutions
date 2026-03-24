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
    // since we require maxValue of left to be smaller than root
    // also, minValue of right to greater than root
    struct Info {
        bool isBST;
        int sum;
        int maxVal;
        int minVal;
    };
    // final ans
    int maxSum = 0;
    Info isValid(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MIN, INT_MAX};
        }
        //will fetch details of left tree
        auto left = isValid(root->left);
        //will fetch details of right tree
        auto right = isValid(root->right);
        if (left.isBST and right.isBST and left.maxVal < root->val and
            right.minVal > root->val) {
            //left tree + root + right tree
            int currSum = left.sum + right.sum + root->val;
            //store ans
            maxSum = max(maxSum, currSum);
            //maxVal can come from right and minVal can come from left
            //min max finction in return
            return {true, currSum, max(right.maxVal, root->val),
                    min(left.minVal, root->val)};
        }
        //tree is discarded
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        isValid(root);
        return maxSum;
    }
};