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
    void inorder(TreeNode*& prev, int& currFreq, int& maxFreq,
                 vector<int>& modes, TreeNode* root,
                 bool isMaxFreqCalculated = false) {
        if (!root) {
            return;
        }
        inorder(prev, currFreq, maxFreq, modes, root->left,
                isMaxFreqCalculated);
        if (!isMaxFreqCalculated) {
            if (prev and prev->val == root->val) {
                currFreq++;
            } else {
                maxFreq = max(maxFreq, currFreq);
                currFreq = 1;
            }
        } else {
            if (prev and prev->val == root->val) {
                currFreq++;
            } else {
                if (prev and currFreq == maxFreq) {
                    modes.push_back(prev->val);
                }
                currFreq = 1;
            }
        }
        prev = root;
        inorder(prev, currFreq, maxFreq, modes, root->right,
                isMaxFreqCalculated);
    }

public:
    vector<int> findMode(TreeNode* root) {
        TreeNode* prev = nullptr;
        int currFreq = 1, maxFreq = 0;
        vector<int> modes;
        inorder(prev, currFreq, maxFreq, modes, root);
        maxFreq = max(maxFreq, currFreq);
        prev = nullptr;
        currFreq = 1;
        inorder(prev, currFreq, maxFreq, modes, root, true);
        if (prev and currFreq == maxFreq) {
            modes.push_back(prev->val);
        }
        return modes;
    }
};