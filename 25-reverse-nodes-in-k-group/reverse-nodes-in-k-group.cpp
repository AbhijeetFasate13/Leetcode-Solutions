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
    ListNode* reverse(ListNode* head, ListNode*& tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        tail = head;
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while (true) {
            bool earlyBreak = false;
            for (int i = 0; i < k; i++) {
                fast = fast->next;
                if (!fast) {
                    earlyBreak = true;
                    break;
                }
            }
            if (earlyBreak) {
                break;
            }
            ListNode* nextToFast = fast->next;
            fast->next = nullptr;
            slow->next = reverse(slow->next, fast);
            fast->next = nextToFast;
            slow = fast;
        }
        return dummy->next;
    }
};