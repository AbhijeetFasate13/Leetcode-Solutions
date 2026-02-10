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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if (root)
            st.push(root);
        vector<int> ans;
        while (!st.empty()) {
            TreeNode* curr = st.top();
            if (curr->left and curr->left->val != -101)
                st.push(curr->left);
            else {
                ans.push_back(curr->val);
                curr->val = -101;
                st.pop();
                if (curr->right and curr->right->val != -101)
                    st.push(curr->right);
            }
        }
        return ans;
    }
};