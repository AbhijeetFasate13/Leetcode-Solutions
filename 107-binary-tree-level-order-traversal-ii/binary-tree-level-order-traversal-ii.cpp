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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> prev;
        if (root)
            prev.push_back(root);
        int itr = 0;
        while (!prev.empty()) {
            vector<TreeNode*> curr;
            ans.push_back({});
            for (const auto& i : prev) {
                if (i->left)
                    curr.push_back(i->left);
                if (i->right)
                    curr.push_back(i->right);
                ans[itr].push_back(i->val);
            }
            prev = curr;
            itr++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};