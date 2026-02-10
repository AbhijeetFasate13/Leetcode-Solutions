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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> level;
        if (root)
            level.push(root);
        while (!level.empty()) {
            int sz = level.size();
            vector<int> currLevel(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* currNode = level.front();
                level.pop();
                currLevel[i] = currNode->val;
                if (currNode->left)
                    level.push(currNode->left);
                if (currNode->right)
                    level.push(currNode->right);
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};