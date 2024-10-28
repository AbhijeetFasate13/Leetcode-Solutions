class Solution {
    int helper(const vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(3, -1);
        if (n == 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i % 3] = max(dp[(i - 1) % 3], dp[(i - 2) % 3] + nums[i]);
        }
        return dp[(n - 1) % 3];
    }

public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 2) {
            if (n == 1)
                return nums[0];
            else
                return max(nums[0], nums[1]);
        }
        vector<int> temp(n - 1);
        for (int i = 0; i < n - 1; i++) {
            temp[i] = nums[i];
        }
        int l = helper(temp);
        for (int i = 1; i < n; i++) {
            temp[i - 1] = nums[i];
        }
        int r = helper(temp);
        return max(l, r);
    }
};