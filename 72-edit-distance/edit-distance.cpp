class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size(), n = (int)word2.size();
        /*
        dp[i][j] states the minimum edits required to match both strings
        from ith place to last in string1 and jth to last in string2
        */
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // If word2 is fully matched (i.e., j == n), remove all remaining chars
        // from word1[i:]
        for (int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }

        // If word1 is fully matched (i.e., i == m), insert all remaining chars
        // from word2[j:]
        for (int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] != word2[j])
                    // dp[i][j] → dp[i][j+1]: insert word2[j] into word1
                    // dp[i][j] → dp[i+1][j]: delete word1[i]
                    // dp[i][j] → dp[i+1][j+1]: replace word1[i] with word2[j]
                    dp[i][j] =
                        1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});
                else
                    // its already a match so move forward in both
                    dp[i][j] = dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};