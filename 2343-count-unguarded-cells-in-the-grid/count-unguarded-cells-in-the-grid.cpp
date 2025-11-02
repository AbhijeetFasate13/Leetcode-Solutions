class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (const auto& i : walls) {
            grid[i[0]][i[1]] = 1;
        }
        for(const auto& i:guards){
            int x = i[0], y = i[1];
            grid[x][y] = 2;
        }
        for (const auto& g : guards) {
            int x = g[0], y = g[1];
            // up
            for (int i = x-1; i >= 0; i--) {
                if (grid[i][y] == 1 or grid[i][y] == 2) {
                    break;
                }
                grid[i][y] = 3;
            }
            // down
            for (int i = x+1; i < m; i++) {
                if (grid[i][y] == 1 or grid[i][y] == 2) {
                    break;
                }
                grid[i][y] = 3;
            }
            // left
            for (int i = y-1; i >= 0; i--) {
                if (grid[x][i] == 1 or grid[x][i] == 2) {
                    break;
                }
                grid[x][i] = 3;
            }
            // right
            for (int i = y+1; i < n; i++) {
                if (grid[x][i] == 1 or grid[x][i] == 2) {
                    break;
                }
                grid[x][i] = 3;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};