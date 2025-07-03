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
    class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (const auto& i : lists) {
            if(i)
                pq.push(i);
        }
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        ListNode* peek;
        while (!pq.empty()) {
            peek = pq.top();
            pq.pop();
            temp->next = peek;
            temp = temp->next;
            if (peek and peek->next) {
                peek = peek->next;
                pq.push(peek);
            }
        }
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};