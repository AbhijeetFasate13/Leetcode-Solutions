class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i += 1) {
            int ans = 0;
            for (int j = 1; j * j <= i; j += 1) {
                if (i % j == 0 and !dp[i - j]) {
                    ans = 1;
                    break;
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};