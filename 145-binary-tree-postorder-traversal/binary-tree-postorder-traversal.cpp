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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;
        vector<int> ans;
        // L R Root
        while (curr or !st.empty()) {
            if (curr) {
                // L
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top();
                // R
                if (temp->right and lastVisited != temp->right) {
                    curr = temp->right;
                }
                // Root
                else {
                    lastVisited = temp;
                    ans.push_back(temp->val);
                    st.pop();
                }
            }
        }
        return ans;
    }
};