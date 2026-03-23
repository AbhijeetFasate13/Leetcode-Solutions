class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp1(m, vector<long long>(n));
        vector<vector<long long>> dp2(m, vector<long long>(n));
        dp1[m - 1][n - 1] = dp2[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                long long mx = LLONG_MIN, mn = LLONG_MAX;
                if (j + 1 < n) {
                    long long a = grid[i][j] * dp1[i][j + 1];
                    long long b = grid[i][j] * dp2[i][j + 1];
                    mx = max({mx, a, b});
                    mn = min({mn, a, b});
                }
                if (i + 1 < m) {
                    long long a = grid[i][j] * dp1[i + 1][j];
                    long long b = grid[i][j] * dp2[i + 1][j];
                    mx = max({mx, a, b});
                    mn = min({mn, a, b});
                }
                dp1[i][j] = mx;
                dp2[i][j] = mn;
            }
        }
        long long ans = dp1[0][0];
        if (ans < 0)
            return -1;
        return ans % 1000000007;
    }
};