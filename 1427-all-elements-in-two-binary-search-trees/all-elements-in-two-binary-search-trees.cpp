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
    void inorder(vector<int>& tree, TreeNode* root) {
        if (!root)
            return;
        inorder(tree, root->left);
        tree.push_back(root->val);
        inorder(tree, root->right);
    }
    void merge(const vector<int>& tree1, const vector<int>& tree2,
               vector<int>& combinedTree) {
        int l = 0, r = 0;
        while (l < tree1.size() and r < tree2.size()) {
            if (tree1[l] < tree2[r]) {
                combinedTree.push_back(tree1[l]);
                l++;
            } else {
                combinedTree.push_back(tree2[r]);
                r++;
            }
        }
        while (l < tree1.size()) {
            combinedTree.push_back(tree1[l]);
            l++;
        }
        while (r < tree2.size()) {
            combinedTree.push_back(tree2[r]);
            r++;
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> combinedTree, tree1, tree2;
        inorder(tree1, root1);
        inorder(tree2, root2);
        merge(tree1, tree2, combinedTree);
        return combinedTree;
    }
};