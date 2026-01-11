/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int steps1 = 0, steps2 = 0;
        while (temp1) {
            temp1 = temp1->next;
            steps1++;
        }
        while (temp2) {
            temp2 = temp2->next;
            steps2++;
        }
        temp1 = headA;
        temp2 = headB;
        if (steps1 > steps2) {
            for (int i = 0; i < steps1 - steps2; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < steps2 - steps1; i++) {
                temp2 = temp2->next;
            }
        }
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};