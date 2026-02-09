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
    void inorder(TreeNode* root, vector<int>& tree) {
        if (!root)
            return;
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> tree;
        inorder(root, tree);
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2, -1));
        for (int i = 0; i < n; i++) {
            auto min = upper_bound(tree.begin(), tree.end(), queries[i]);
            if (min != tree.begin()) {
                min--;
                ans[i][0] = *min;
            }
            auto max = lower_bound(tree.begin(), tree.end(), queries[i]);
            if (max != tree.end()) {
                ans[i][1] = *max;
            }
        }

        return ans;
    }
};