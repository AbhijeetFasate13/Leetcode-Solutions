/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents = getParents(root);
        queue<TreeNode*> q;
        set<TreeNode*> visited;
        q.push(target);
        while (k--) {
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
        }
        vector<int> nodesAtDistK;
        while (!q.empty()) {
            nodesAtDistK.push_back(q.front()->val);
            q.pop();
        }
        return nodesAtDistK;
    }
};