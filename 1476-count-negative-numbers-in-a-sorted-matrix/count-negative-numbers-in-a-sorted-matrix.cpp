class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int negativeCount = 0;
        for (int i = 0; i < rows; i++) {
            int negsInCurrRow =
                (lower_bound(grid[i].rbegin(), grid[i].rend(), 0) -
                 grid[i].rbegin());
            negativeCount += negsInCurrRow;
        }
        return negativeCount;
    }
};