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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next and !head->next->next)
            return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1, prevCritIdx = -1, firstCritIdx = -1;
        vector<int> ans(2, INT_MAX);

        while (curr->next) {
            if ((curr->val > prev->val and curr->val > curr->next->val) or
                (curr->val < prev->val and curr->val < curr->next->val)) {
                if (firstCritIdx == -1) {
                    firstCritIdx = idx;
                }
                ans[0] = prevCritIdx == -1 ? INT_MAX
                                           : min(ans[0], idx - prevCritIdx);
                ans[1] = idx - firstCritIdx;
                prevCritIdx = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if (ans[0] == INT_MAX)
            ans[0] = -1;
        if (ans[1] == INT_MAX or ans[1]==0)
            ans[1] = -1;
        return ans;
    }
};