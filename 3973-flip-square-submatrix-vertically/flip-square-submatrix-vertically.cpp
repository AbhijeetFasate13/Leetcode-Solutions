class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        vector<vector<int>> updatedGrid = grid;
        for (int i = x; i < x + k / 2; i++) {
            for (int j = y; j < y + k; j++) {
                swap(updatedGrid[i][j], updatedGrid[x + k - 1 - i + x][j]);
            }
        }
        return updatedGrid;
    }
};