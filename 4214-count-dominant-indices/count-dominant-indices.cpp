class Solution {
    int average(const int& idx, const vector<int>& suffix) {
        int total = suffix.size() - idx;
        return suffix[idx] / total;
    }

public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > average(i + 1, suffix))
                count++;
        }
        return count;
    }
};