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
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1, prevCritIdx = -1, firstCritIdx = -1;
        vector<int> ans(2, -1);

        while (curr->next) {
            if ((curr->val > prev->val and curr->val > curr->next->val) or
                (curr->val < prev->val and curr->val < curr->next->val)) {

                if (firstCritIdx == -1)
                    firstCritIdx = idx;

                if (prevCritIdx != -1)
                    ans[0] = ans[0] == -1 ? idx - prevCritIdx
                                          : min(ans[0], idx - prevCritIdx);

                if (idx != firstCritIdx)
                    ans[1] = idx - firstCritIdx;
                prevCritIdx = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        return ans;
    }
};