class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        vector<long long> rows(m), cols(n);
        long long int rowSum = 0;
        for (int i = 0; i < m; i++) {
            rowSum = 0;
            for (int j = 0; j < n; j++) {
                cols[j] += grid[i][j];
                rowSum += grid[i][j];
            }
            rows[i] = rowSum;
            total += rowSum;
        }
        if (total == 0)
            return true;
        long long int runningSum = 0;
        for (int i = 0; i < m; i++) {
            runningSum += rows[i];
            if (runningSum * 2 == total)
                return true;
        }
        runningSum = 0;
        for (int i = 0; i < n; i++) {
            runningSum += cols[i];
            if (runningSum * 2 == total)
                return true;
        }
        return false;
    }
};