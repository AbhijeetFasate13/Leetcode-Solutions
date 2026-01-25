class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int minDiff = nums[k - 1] - nums[0];
        for (int i = k; i < n; i++) {
            minDiff = min(minDiff, nums[i] - nums[i - k + 1]);
        }
        return minDiff;
    }
};