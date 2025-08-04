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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        int count = 0;
        if (root) {
            q.push(root);
            count++;
        }
        while (!q.empty()) {
            const auto& i = q.front();
            if (i->left) {
                count++;
                q.push(i->left);
            }
            if (i->right) {
                count++;
                q.push(i->right);
            }
            q.pop();
        }
        return count;
    }
};