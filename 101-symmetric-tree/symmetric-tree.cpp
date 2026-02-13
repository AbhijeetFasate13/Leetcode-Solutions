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
    bool isPalindrome(const vector<TreeNode*>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            if (!arr[l] and !arr[r]) {
                l++;
                r--;
                continue;
            }
            if (!arr[l] or !arr[r])
                return false;
            if (arr[l] and arr[r] and arr[l++]->val != arr[r--]->val)
                return false;
        }
        return true;
    }

public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> prev;
        prev.push_back(root);
        int sz;
        while (!prev.empty()) {
            if (!isPalindrome(prev))
                return false;
            sz = prev.size();
            vector<TreeNode*> curr;
            for (int i = 0; i < sz; i++) {
                if (!prev[i])
                    continue;
                curr.push_back(prev[i]->left);
                curr.push_back(prev[i]->right);
            }
            prev = curr;
        }
        return true;
    }
};