class Solution {
    int m, n;
    vector<vector<vector<int>>> dp;

    int rec(int i, int j, int k, vector<vector<int>>& coins) {
        if (i >= m || j >= n) return INT_MIN;
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && k > 0)
                return 0;
            return coins[i][j];
        }

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
        int val = coins[i][j];
        int bestNext = max(rec(i + 1, j, k, coins),
                           rec(i, j + 1, k, coins));

        int ans = val + bestNext;
        if (val < 0 && k > 0) {
            int bestNeutral = max(rec(i + 1, j, k - 1, coins),
                                  rec(i, j + 1, k - 1, coins));
            ans = max(ans, bestNeutral);
        }

        return dp[i][j][k] = ans;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        return rec(0, 0, 2, coins);
    }
};