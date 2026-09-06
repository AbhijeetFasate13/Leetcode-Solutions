class Solution {
    const int mod = 1e9+7;
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));

        // one way to make empty target from empty source
        dp[0][0] = 1;

        // every char from s can make an empty target
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // empty source cannot make a non-empty target;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i][j]+dp[i - 1][j - 1])%mod;
            }
        }

        return dp[m][n];
    }
};