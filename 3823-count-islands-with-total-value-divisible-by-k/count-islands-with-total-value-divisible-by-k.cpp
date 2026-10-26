class Solution {
    int m, n;
    long long getIslandTotalValue(int i, int j, vector<vector<int>>& visited,
                                  const vector<vector<int>>& grid) {
        if (i >= m or i < 0 or j >= n or j < 0 or visited[i][j] or
            grid[i][j] == 0)
            return 0;
        visited[i][j] = 1;
        long long up = getIslandTotalValue(i - 1, j, visited, grid);
        long long down = getIslandTotalValue(i + 1, j, visited, grid);
        long long left = getIslandTotalValue(i, j - 1, visited, grid);
        long long right = getIslandTotalValue(i, j + 1, visited, grid);

        return up + down + left + right + grid[i][j];
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                if (!visited[i][j]) {
                    count += getIslandTotalValue(i, j, visited, grid) % k == 0;
                }
            }
        }
        return count;
    }
};