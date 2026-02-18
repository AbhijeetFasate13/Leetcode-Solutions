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
    void preorder(TreeNode* root, vector<int>& curr, vector<vector<int>>& ans) {
        if (!root)
            return;

        curr.push_back(root->val);

        if (!root->left && !root->right) {
            ans.push_back(curr);
        }

        preorder(root->left, curr, ans);
        preorder(root->right, curr, ans);

        curr.pop_back();
    }

    vector<string> transform(const vector<vector<int>>& arr) {
        vector<string> ans;
        for (const auto& v : arr) {
            string curr;
            for (int i = 0; i < v.size(); i++) {
                if (i > 0) {
                    curr += "->";
                }
                curr += to_string(v[i]);
            }
            ans.push_back(curr);
        }
        return ans;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> curr;
        preorder(root, curr, ans);
        return transform(ans);
    }
};