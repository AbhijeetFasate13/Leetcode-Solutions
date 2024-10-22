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
    vector<int> ans;
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }
    bool isSorted() {
        int prev = ans[0];
        for (int i = 1; i < (int)ans.size(); i++) {
            if (prev < ans[i]) {
                prev = ans[i];
            } else {
                return false;
            }
        }
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return isSorted();
    }
};