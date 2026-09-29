class Solution {
    int m, n;
    vector<vector<vector<int>>> dp;
    bool helper(int i, int j, int open, const vector<vector<char>>& grid) {

        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(')
            open++;
        else
            open--;

        if (open < 0)
            return false;

        int remaining = (m - i - 1) + (n - j - 1);
        if (open > remaining)
            return false;

        if (i == m - 1 && j == n - 1)
            return open == 0;

        if (dp[i][j][open] != -1)
            return dp[i][j][open];

        return dp[i][j][open] =
                   helper(i + 1, j, open, grid) || helper(i, j + 1, open, grid);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n, -1)));

        return helper(0, 0, 0, grid);
    }
};