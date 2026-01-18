class Solution {
    vector<vector<int>> prefixH, prefixV;
    int rows, cols;
    void pre(vector<vector<int>>& grid) {
        prefixH.assign(rows, vector<int>(cols, 0));
        prefixV.assign(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefixH[i][j] = grid[i][j] + (j > 0 ? prefixH[i][j - 1] : 0);
            }
        }

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                prefixV[i][j] = grid[i][j] + (i > 0 ? prefixV[i - 1][j] : 0);
            }
        }
    }

    bool checkMagicSquare(int row, int col, int sz, vector<vector<int>>& grid) {
        int target =
            prefixH[row][col + sz - 1] - (col > 0 ? prefixH[row][col - 1] : 0);

        for (int i = 0; i < sz; i++) {
            int r = row + i;
            int sumRow =
                prefixH[r][col + sz - 1] - (col > 0 ? prefixH[r][col - 1] : 0);
            if (sumRow != target)
                return false;
        }

        for (int j = 0; j < sz; j++) {
            int c = col + j;
            int sumCol =
                prefixV[row + sz - 1][c] - (row > 0 ? prefixV[row - 1][c] : 0);
            if (sumCol != target)
                return false;
        }

        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < sz; i++) {
            diag1 += grid[row + i][col + i];
            diag2 += grid[row + i][col + sz - 1 - i];
        }

        return diag1 == target && diag2 == target;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        pre(grid);

        int ans = 1;

        for (int sz = 2; sz <= min(rows, cols); sz++) {
            bool found = false;
            for (int r = 0; r <= rows - sz && !found; r++) {
                for (int c = 0; c <= cols - sz; c++) {
                    if (checkMagicSquare(r, c, sz, grid)) {
                        found = true;
                        break;
                    }
                }
            }
            if (found)
                ans = sz;
        }
        return ans;
    }
};
