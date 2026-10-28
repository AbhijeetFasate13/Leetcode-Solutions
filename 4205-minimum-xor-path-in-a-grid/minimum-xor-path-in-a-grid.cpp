class Solution {
    int m, n;
    vector<vector<bitset<1024>>> dp;
    vector<vector<bool>> visited;

    bitset<1024> rec(int i, int j, vector<vector<int>>& grid) {
        if (visited[i][j])
            return dp[i][j];

        visited[i][j] = true;

        if (i == m - 1 && j == n - 1) {
            dp[i][j].set(grid[i][j]);
            return dp[i][j];
        }

        bitset<1024> ans;

        if (i + 1 < m) {
            auto down = rec(i + 1, j, grid);

            for (int x = 0; x < 1024; x++) {
                if (down[x])
                    ans.set(grid[i][j] ^ x);
            }
        }

        if (j + 1 < n) {
            auto right = rec(i, j + 1, grid);

            for (int x = 0; x < 1024; x++) {
                if (right[x])
                    ans.set(grid[i][j] ^ x);
            }
        }

        return dp[i][j] = ans;
    }

public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<bitset<1024>>(n));
        visited.assign(m, vector<bool>(n, false));

        auto possible = rec(0, 0, grid);

        for (int x = 0; x < 1024; x++) {
            if (possible[x])
                return x;
        }

        return -1;
    }
};