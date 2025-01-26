class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int sz = *max_element(nums.begin(), nums.end());
        vector<int> freq(sz + 1);
        int mostFreq;
        vector<pair<int, int>> pos(sz + 1, {-1, -1});
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (pos[nums[i]].first == -1) {
                pos[nums[i]].first = i;
            }
            pos[nums[i]].second = i;
        }
        int ans = n;
        mostFreq = *max_element(freq.begin(), freq.end());
        for (int i = 0; i <= sz; i++) {
            if (freq[i] == mostFreq) {
                ans = min(ans, pos[i].second - pos[i].first + 1);
            }
        }
        return ans;
    }
};