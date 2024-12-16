class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = (int)nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto [a, b] = pq.top();
            pq.pop();
            a *= multiplier;
            pq.push({a, b});
        }
        while (!pq.empty()) {
            auto [a, b] = pq.top();
            pq.pop();
            nums[b] = a;
        }
        return nums;
    }
};