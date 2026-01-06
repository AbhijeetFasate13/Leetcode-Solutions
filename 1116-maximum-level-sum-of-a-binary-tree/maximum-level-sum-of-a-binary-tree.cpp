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
public:
    int maxLevelSum(TreeNode* root) {
        if (!root->left and !root->right)
            return 1;
        int level = 1, maxLevel = 1, maxSum = root->val, sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            int sz = q.size();
            sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                    sum += curr->left->val;
                }
                if (curr->right) {
                    q.push(curr->right);
                    sum += curr->right->val;
                }
            }
            if (q.empty())
                break;
            if (sum > maxSum) {
                maxLevel = level;
                maxSum = sum;
            }
        }
        return maxLevel;
    }
};