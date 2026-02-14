class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101));
        dp[0][0] = poured;
        for (int row = 0; row <= query_row; row++) {
            for (int col = 0; col <= query_glass; col++) {
                if (dp[row][col] > 1.0) {
                    double overflow = (dp[row][col] - 1) / 2.0;
                    dp[row + 1][col] += overflow;
                    dp[row + 1][col + 1] += overflow;
                    dp[row][col] = 1.0;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};