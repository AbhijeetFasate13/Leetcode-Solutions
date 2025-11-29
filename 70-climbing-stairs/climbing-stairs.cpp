class Solution {
    int dp[46];

public:
    Solution() { memset(dp, -1, sizeof(dp)); }
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};