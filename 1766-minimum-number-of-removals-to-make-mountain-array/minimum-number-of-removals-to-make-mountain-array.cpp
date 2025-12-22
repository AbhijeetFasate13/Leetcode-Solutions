class Solution {
    vector<int> helper(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = helper(nums);
        reverse(nums.begin(), nums.end());
        vector<int> right = helper(nums);
        reverse(right.begin(), right.end());

        int maxMountain = 0;
        for (int i = 1; i < n - 1; i++) {
            if (left[i] > 1 && right[i] > 1) {
                maxMountain = max(maxMountain, left[i] + right[i] - 1);
            }
        }
        return n - maxMountain;
    }
};
