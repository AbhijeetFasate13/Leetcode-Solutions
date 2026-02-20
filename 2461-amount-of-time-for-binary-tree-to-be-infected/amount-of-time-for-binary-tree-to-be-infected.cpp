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
    unordered_map<TreeNode*, TreeNode*> getParents(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    parents[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right) {
                    parents[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        return parents;
    }
    TreeNode* getStart(TreeNode* root, const int& start) {
        if (!root)
            return root;
        TreeNode* l = getStart(root->left, start);
        if (l)
            return l;
        if (root->val == start)
            return root;
        return getStart(root->right, start);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parents = getParents(root);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        TreeNode* target = getStart(root, start);
        q.push(target);
        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                visited.insert(curr);
                if (parents.find(curr) != parents.end() and
                    !visited.count(parents[curr]))
                    q.push(parents[curr]);
                if (curr->left and !visited.count(curr->left))
                    q.push(curr->left);
                if (curr->right and !visited.count(curr->right))
                    q.push(curr->right);
            }
            time++;
        }
        return time - 1;
    }
};