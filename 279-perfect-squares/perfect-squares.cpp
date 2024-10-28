class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int minReq = INT_MAX;
            for (int j = 1; j * j <= i; j += 1) {
                minReq = min(minReq, 1 + dp[i - j * j]);
            }
            dp[i] = minReq;
        }
        return dp[n];
    }
};