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
    void bfs(queue<pair<TreeNode*, pair<int, int>>>& q,
             map<int, map<int, multiset<int>>>& mp) {
        int n;
        while (!q.empty()) {
            n = q.size();
            for (int i = 0; i < n; i++) {
                auto curr = q.front();
                int row = curr.second.second;
                int col = curr.second.first;
                q.pop();
                mp[col][row].insert(curr.first->val);
                if (curr.first->left)
                    q.push({curr.first->left, {col - 1, row + 1}});
                if (curr.first->right)
                    q.push({curr.first->right, {col + 1, row + 1}});
            }
        }
    }

    void fillAns(const map<int, map<int, multiset<int>>>& mp,
                 vector<vector<int>>& ans) {
        for (const auto col : mp) {
            vector<int> curr;
            for (const auto it : col.second) {
                for (const auto val : it.second) {
                    curr.push_back(val);
                }
            }
            ans.push_back(curr);
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        bfs(q, mp);
        vector<vector<int>> ans;
        fillAns(mp, ans);
        return ans;
    }
};