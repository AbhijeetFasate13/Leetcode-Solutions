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
class BSTIterator {
    vector<int> tree;
    int itr;

public:
    BSTIterator(TreeNode* root) {
        flattenTree(root);
        itr = 0;
    }

    void flattenTree(TreeNode* root) {
        if (!root)
            return;
        flattenTree(root->left);
        tree.push_back(root->val);
        flattenTree(root->right);
    }

    int next() { return tree[itr++]; }

    bool hasNext() { return itr < tree.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */