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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto& list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            if (curr->next) {
                pq.push(curr->next);
            }
        }
        
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};
