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
class Solution {
    int calcLen(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int len = calcLen(head);
        k %= len;
        if (k == 0)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        ListNode* ans = slow->next;
        slow->next = nullptr;
        return ans;
    }
};