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
    void insert(const int& data, TreeNode*& root) {
        if (data < root->val) {
            if (root->left) {
                insert(data, root->left);
            } else {
                root->left = new TreeNode(data);
            }
        } else {
            if (root->right) {
                insert(data, root->right);
            } else {
                root->right = new TreeNode(data);
            }
        }
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;
        while (i < preorder.size()) {
            insert(preorder[i++], root);
        }
        return root;
    }
};