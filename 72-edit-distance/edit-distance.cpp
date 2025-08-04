class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // dp[i][j] states minimum edits to require word1[0:i] to match
        // word2[0:j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // if word2 is exhausted then, we need to remove all characters
        // from word1
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // if word1 is exhausted then, we need to insert all characters
        // from word2
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // exact match, move forward
                } else {
                    // dp[i][j] = dp[i-1][j]     → delete word1[i-1]
                    // dp[i][j] = dp[i][j-1]     → insert word2[j-1] into word1
                    // dp[i][j] = dp[i-1][j-1]   → replace word1[i-1] with word2[j-1]
                    dp[i][j] =
                        1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n]; // final answer to match both words
    }
};