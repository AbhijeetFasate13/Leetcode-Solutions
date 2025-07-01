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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(temp){
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
};