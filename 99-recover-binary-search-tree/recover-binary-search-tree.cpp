class Solution {
    void inorderTraverse(TreeNode*& prev, TreeNode* root,
                         vector<TreeNode*>& nodes) {
        if (!root)
            return;
        inorderTraverse(prev, root->left, nodes);
        if (prev && prev->val > root->val) {
            if (nodes.empty()) {
                nodes.push_back(prev);
                nodes.push_back(root);
            } else {
                nodes[1] = root;
            }
        }
        prev = root;
        inorderTraverse(prev, root->right, nodes);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> swappedNodes;
        TreeNode* prev = nullptr;
        inorderTraverse(prev, root, swappedNodes);
        swap(swappedNodes[0]->val, swappedNodes[1]->val);
    }
};
