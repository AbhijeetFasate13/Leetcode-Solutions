class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> traceLIS(n);
        iota(begin(traceLIS), end(traceLIS), 0);
        int ans = 1, ind = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0 or
                    nums[j] % nums[i] == 0) and dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    traceLIS[i] = j;
                }
            }
            if (ans < dp[i]) {
                ans = dp[i];
                ind = i;
            }
        }
        vector<int> LIS;

        while (traceLIS[ind] != ind) {
            LIS.push_back(nums[ind]);
            ind = traceLIS[ind];
        }
        LIS.push_back(nums[ind]);
        reverse(begin(LIS), end(LIS));
        return LIS;
    }
};