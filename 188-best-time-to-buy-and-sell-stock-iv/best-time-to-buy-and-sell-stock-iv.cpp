class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0)
            return 0;

        vector<vector<int>> curr(k + 1, vector<int>(2, 0));
        vector<vector<int>> prev(k + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                curr[j][1] = max(prices[i] + prev[j + 1][0], prev[j][1]);
                curr[j][0] = max(-prices[i] + prev[j][1], prev[j][0]);
            }
            prev = curr;
        }

        return prev[0][0];
    }
};
