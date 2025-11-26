class Solution {
    vector<vector<vector<int>>> dp;
    int n, m, mod;
    int rec(int row, int col, vector<vector<int>>& grid, int sum, int k) {
        if (row == n - 1 and col == m - 1) {
            sum += grid[row][col];
            sum %= k;
            if (sum == 0) {
                return 1;
            }
            return 0;
        }
        if (row == n) {
            return 0;
        }
        if (col == m) {
            return 0;
        }
        if (dp[row][col][sum] != -1) {
            return dp[row][col][sum];
        }
        int total = 0;
        total += rec(row, col + 1, grid, (sum + grid[row][col]) % k, k) % mod;
        total += rec(row + 1, col, grid, (sum + grid[row][col]) % k, k) % mod;
        return dp[row][col][sum] = total % mod;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        mod = 1e9 + 7;
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return rec(0, 0, grid, 0, k);
    }
};