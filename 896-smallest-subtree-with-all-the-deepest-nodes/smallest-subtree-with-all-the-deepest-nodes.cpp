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
    unordered_map<int, int> depth;
    int maxDepth = 0;

    void calcDepth(TreeNode* root, int d) {
        if (!root) {
            return;
        }
        maxDepth = max(maxDepth, d);
        depth[root->val] = d;
        calcDepth(root->left, d + 1);
        calcDepth(root->right, d + 1);
    }

    TreeNode* LCA(TreeNode* root) {
        if (!root or depth[root->val] == maxDepth) {
            return root;
        }
        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);
        if (l and r)
            return root;
        return l ? l : r;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        calcDepth(root, 0);
        return LCA(root);
    }
};