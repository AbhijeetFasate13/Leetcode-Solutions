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
    void preorder(TreeNode* root, string& curr, vector<string>& ans) {
        if (!root)
            return;

        int len = curr.size();

        if (!curr.empty())
            curr += "->";

        curr += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(curr);
        }

        preorder(root->left, curr, ans);
        preorder(root->right, curr, ans);

        curr.resize(len);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr;
        preorder(root, curr, ans);
        return ans;
    }
};