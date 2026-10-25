
class Solution {
    int m, n;
    bool traverse(int i, int j, vector<vector<int>>& visited,
                  const vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (grid[i][j] == 1 || visited[i][j])
            return true;

        visited[i][j] = 1;

        bool up = traverse(i - 1, j, visited, grid);
        bool down = traverse(i + 1, j, visited, grid);
        bool left = traverse(i, j - 1, visited, grid);
        bool right = traverse(i, j + 1, visited, grid);

        return up && down && left && right;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (traverse(i, j, visited, grid))
                        count++;
                }
            }
        }

        return count;
    }
};
