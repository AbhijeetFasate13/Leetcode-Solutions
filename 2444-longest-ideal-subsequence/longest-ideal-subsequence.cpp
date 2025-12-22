class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int ans = 0;

        for (char c : s) {
            int ci = c - 'a';
            int best = 0;

            for (int j = max(0, ci - k); j <= min(25, ci + k); j++) {
                best = max(best, dp[j]);
            }

            dp[ci] = max(dp[ci], best + 1);
            ans = max(ans, dp[ci]);
        }

        return ans;
    }
};
