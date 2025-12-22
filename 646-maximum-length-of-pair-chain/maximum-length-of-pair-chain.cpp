class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs), end(pairs));
        vector<int> dp(n, 1);
        int maxx = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxx = max(maxx, dp[i]);
        }
        return maxx;
    }
};