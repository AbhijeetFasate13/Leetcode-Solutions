class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(), cols = strs[0].size();
        vector<int> dp(cols, 1);
        int ans = 1;
        for (int i = 1; i < cols; i++) {
            for (int j = 0; j < i; j++) {
                bool sorted = true;
                for (int row = 0; row < rows; row++) {
                    if (strs[row][j] > strs[row][i]) {
                        sorted = false;
                        break;
                    }
                }
                if (sorted) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return cols - ans;
    }
};