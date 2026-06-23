class Solution {
public:
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        r -= l;
        vector<vector<int>> prev_dp(r + 1, vector<int>(2, 0)),
            curr_dp(r + 1, vector<int>(2, 0));
        for (int j = 0; j <= r; j++) {
            prev_dp[j][0] = j + 1;
            prev_dp[j][1] = j + 1;
        }
        for (int i = 1; i < n; i++) {

            for (int j = 0; j <= r; j++) {
                curr_dp[j][0] = 0;
                curr_dp[j][1] = 0;
            }

            for (int j = 0; j <= r; j++) {
                if (j == 0) {
                    curr_dp[j][0] = (prev_dp[r][1] - prev_dp[j][1] + mod) % mod;
                } else if (j == r) {
                    curr_dp[j][1] = prev_dp[j - 1][0];
                    curr_dp[j][1] = (curr_dp[j][1] + curr_dp[j - 1][1]) % mod;
                    curr_dp[j][0] = curr_dp[j - 1][0];
                } else {
                    curr_dp[j][0] = (prev_dp[r][1] - prev_dp[j][1] + mod) % mod;
                    curr_dp[j][0] = (curr_dp[j][0] + curr_dp[j - 1][0]) % mod;

                    curr_dp[j][1] = prev_dp[j - 1][0];
                    curr_dp[j][1] = (curr_dp[j][1] + curr_dp[j - 1][1]) % mod;
                }
            }
            swap(prev_dp, curr_dp);
        }

        return (prev_dp[r][0] + prev_dp[r][1]) % mod;
    }
};