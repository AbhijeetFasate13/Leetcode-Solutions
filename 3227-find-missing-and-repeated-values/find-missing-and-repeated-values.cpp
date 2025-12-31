class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                while (i * n + j + 1 != grid[i][j] and
                       grid[i][j] !=
                           grid[(grid[i][j] - 1) / n][(grid[i][j] - 1) % n]) {
                    swap(grid[i][j],
                         grid[(grid[i][j] - 1) / n][(grid[i][j] - 1) % n]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != i * n + j + 1) {
                    ans[0] = grid[i][j];
                    ans[1] = i * n + j + 1;
                    break;
                }
            }
        }
        return ans;
    }
};