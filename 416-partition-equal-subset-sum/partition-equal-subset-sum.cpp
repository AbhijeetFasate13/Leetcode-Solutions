class Solution {
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int tempSum, int sum, int i) {
        if (i == nums.size() or tempSum * 2 >= sum) {
            return tempSum * 2 == sum ? 1 : 0;
        }
        if (dp[i][tempSum] != -1) {
            return dp[i][tempSum];
        }
        if (nums[i] + tempSum > sum) {
            return dp[i][tempSum] = helper(nums, tempSum, sum, i + 1);
        } else {
            return dp[i][tempSum] =
                       max(helper(nums, tempSum + nums[i], sum, i + 1),
                           helper(nums, tempSum, sum, i + 1));
        }
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum & 1)
            return false;
        dp.resize(nums.size(), vector<int>(sum + 1, -1));
        return helper(nums, 0, sum, 0) == 1;
    }
};