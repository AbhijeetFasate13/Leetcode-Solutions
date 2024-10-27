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
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = new ListNode(0);
        ListNode* high = new ListNode(0);
        ListNode* temp1 = low;
        ListNode* temp2 = high;
        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                temp1->next = temp;
                temp1 = temp1->next;
            } else {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp2->next = nullptr;
        temp1->next = high->next;
        temp = low->next;
        delete low;
        delete high;
        return temp;
    }
};