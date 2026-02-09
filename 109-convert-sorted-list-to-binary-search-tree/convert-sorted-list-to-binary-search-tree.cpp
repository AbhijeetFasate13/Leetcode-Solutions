/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* findMid(ListNode* head, ListNode*& prev) {
        ListNode* slow = head;
        ListNode* fast = head;
        prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* prevToMid = nullptr;
        ListNode* mid = findMid(head, prevToMid);
        if (prevToMid)
            prevToMid->next = nullptr;
        TreeNode* root = new TreeNode(mid->val);
        root->left = mid == head ? nullptr : sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};