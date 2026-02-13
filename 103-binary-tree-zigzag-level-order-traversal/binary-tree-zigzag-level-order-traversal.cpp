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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> prev;
        if (root)
            prev.push_back(root);
        int itr = 0, n;
        TreeNode* currNode;
        while (!prev.empty()) {
            vector<TreeNode*> curr;
            n = prev.size();
            ans.push_back({});
            for (int i = 0; i < n; i++) {
                currNode = prev[i];
                if (currNode->left)
                    curr.push_back(currNode->left);
                if (currNode->right)
                    curr.push_back(currNode->right);
                ans[itr].push_back(currNode->val);
            }
            if (itr & 1) {
                reverse(begin(ans[itr]), end(ans[itr]));
            }
            itr++;
            prev = curr;
        }
        return ans;
    }
};