class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<long long>> dp(rows, vector<long long>(cols));
        if (grid[rows - 1][cols - 1] == 0)
            dp[rows - 1][cols - 1] = 1;
        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                if (grid[r][c] == 1)
                    continue;
                if (r + 1 < rows) {
                    dp[r][c] += dp[r + 1][c];
                }
                if (c + 1 < cols) {
                    dp[r][c] += dp[r][c + 1];
                }
            }
        }
        return dp[0][0];
    }
};