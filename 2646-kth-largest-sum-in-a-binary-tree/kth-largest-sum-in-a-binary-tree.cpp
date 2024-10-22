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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        pq.push(root->val);
        long long sum;
        while (!q.empty()) {
            sum = 0;
            int n = (int)q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    sum += temp->left->val;
                    q.push(temp->left);
                }
                if (temp->right) {
                    sum += temp->right->val;
                    q.push(temp->right);
                }
            }
            if (sum != 0)
                pq.push(sum);
        }
        if (pq.size() < k)
            return -1;
        while (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};