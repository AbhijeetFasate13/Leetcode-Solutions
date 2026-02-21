class Solution {
    ListNode* findMid(ListNode* head, ListNode*& prev) {
        prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

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

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* mid = findMid(head, prev);
        if (prev)
            prev->next = nullptr;
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};