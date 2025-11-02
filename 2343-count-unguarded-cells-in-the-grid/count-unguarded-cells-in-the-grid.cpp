class Solution {
    void populate(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // left to right
        for (int i = 0; i < m; i++) {
            bool guardBehind = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    guardBehind = false;
                else if (grid[i][j] == 2)
                    guardBehind = true;
                else if (guardBehind)
                    grid[i][j] = 3;
            }
        }
        // right to left
        for (int i = 0; i < m; i++) {
            bool guardBehind = false;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1)
                    guardBehind = false;
                else if (grid[i][j] == 2)
                    guardBehind = true;
                else if (guardBehind)
                    grid[i][j] = 3;
            }
        }
        // top to bottom
        for (int j = 0; j < n; j++) {
            bool guardBehind = false;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1)
                    guardBehind = false;
                else if (grid[i][j] == 2)
                    guardBehind = true;
                else if (guardBehind)
                    grid[i][j] = 3;
            }
        }

        // bottom to top
        for (int j = 0; j < n; j++) {
            bool guardBehind = false;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 1)
                    guardBehind = false;
                else if (grid[i][j] == 2)
                    guardBehind = true;
                else if (guardBehind)
                    grid[i][j] = 3;
            }
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (const auto& i : walls) {
            grid[i[0]][i[1]] = 1;
        }
        for (const auto& i : guards) {
            grid[i[0]][i[1]] = 2;
        }
        populate(grid);
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
                if (!grid[i][j]) {
                    count++;
                }
            }
            cout << endl;
        }
        return count;
    }
};