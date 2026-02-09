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
    void insert(TreeNode* root, TreeNode* subTree) {
        if (root->val > subTree->val) {
            if (root->left)
                insert(root->left, subTree);
            else
                root->left = subTree;
        } else {
            if (root->right)
                insert(root->right, subTree);
            else
                root->right = subTree;
        }
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            if (!l and !r)
                return nullptr;
            if (l and r) {
                insert(r, l);
                swap(r->val, root->val);
                TreeNode* temp = r;
                l = temp->left;
                r = temp->right;
                root->left = l;
                root->right = r;
            } else if (!r) {
                swap(l->val, root->val);
                root->right = l->right;
                root->left = l->left;
            } else {
                swap(r->val, root->val);
                root->right = r->right;
                root->left = r->left;
            }
            return root;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};