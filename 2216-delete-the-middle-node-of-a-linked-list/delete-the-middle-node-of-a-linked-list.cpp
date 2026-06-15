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
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};