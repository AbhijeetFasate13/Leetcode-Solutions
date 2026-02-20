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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> preorderLeft, preorderRight, inorderLeft, inorderRight;
        int n = inorder.size();
        bool foundRoot = false;
        for (int i = 0; i < n; i++) {
            if (!foundRoot and inorder[i] == root->val) {
                foundRoot = true;
                continue;
            }
            if (!foundRoot) {
                inorderLeft.push_back(inorder[i]);
            } else {
                inorderRight.push_back(inorder[i]);
            }
        }
        vector<int> temp = inorderLeft;
        sort(begin(temp), end(temp));
        bool foundFirstRight = false;
        for (int i = 1; i < n; i++) {
            if (!foundFirstRight and
                !binary_search(begin(temp), end(temp), preorder[i])) {
                foundFirstRight = true;
            }
            if (!foundFirstRight) {
                preorderLeft.push_back(preorder[i]);
            } else {
                preorderRight.push_back(preorder[i]);
            }
        }
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};