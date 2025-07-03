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
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while (a && b) {
            if (a->val < b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        temp->next = a ? a : b;
        temp = dummy->next;
        delete dummy;
        return temp;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        deque<ListNode*> merged;
        for (const auto& i : lists) {
            if (i)
                merged.push_back(i);
        }
        if (merged.empty())
            return nullptr;
        while (merged.size() > 1) {
            merged.push_back(mergeTwo(merged[0], merged[1]));
            merged.pop_front();
            merged.pop_front();
        }
        return merged[0];
    }
};