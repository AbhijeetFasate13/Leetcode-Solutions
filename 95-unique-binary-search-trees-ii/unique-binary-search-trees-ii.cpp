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
    unordered_map<string, TreeNode*> mp;
    TreeNode* placeNode(int x, TreeNode* root) {
        if (!root)
            return new TreeNode(x);

        if (x < root->val) {
            root->left = placeNode(x, root->left);
        } else {
            root->right = placeNode(x, root->right);
        }

        return root;
    }

    TreeNode* buildBST(vector<int>& tree) {
        if (tree.empty())
            return nullptr;

        TreeNode* root = new TreeNode(tree[0]);

        for (int i = 1; i < tree.size(); i++) {
            root = placeNode(tree[i], root);
        }

        return root;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q)
            return true;

        if (!p or !q)
            return false;

        return p->val == q->val && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    string serialize(TreeNode* root) {
        if (!root)
            return "#";

        return to_string(root->val) + "," + serialize(root->left) + "," +
               serialize(root->right);
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> seq(n);
        iota(seq.begin(), seq.end(), 1);

        vector<TreeNode*> ans;

        do {
            TreeNode* curr = buildBST(seq);
            string serializedTree = serialize(curr);
            if (!mp.count(serializedTree))
                ans.push_back(curr);
            mp[serializedTree] = curr;
        } while (next_permutation(seq.begin(), seq.end()));

        return ans;
    }
};