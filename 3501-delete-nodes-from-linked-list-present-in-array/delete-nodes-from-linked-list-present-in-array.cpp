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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(begin(nums), end(nums));
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp and temp->next) {
            ListNode* toBeDeleted;
            if (binary_search(begin(nums), end(nums), temp->val)) {
                swap(temp->val, temp->next->val);
                toBeDeleted = temp->next;
                temp->next = temp->next->next;
                delete toBeDeleted;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        if (binary_search(begin(nums), end(nums), temp->val)) {
            prev->next = nullptr;
            delete temp;
        }
        return head;
    }
};