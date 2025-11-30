class Solution {
    vector<vector<int>> dp;
    int rec(int idx, int hold, vector<int>& prices) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][hold] != -1) {
            return dp[idx][hold];
        }
        int buy = 0, sell = 0, skip = 0;
        // no stock holding
        if (hold == 0) {
            // buy
            buy += -prices[idx] + rec(idx + 1, 1, prices);
        }
        // already hold a stock
        else {
            // sell
            sell += prices[idx] + rec(idx + 1, 0, prices);
        }
        // skip buying or selling
        skip += rec(idx + 1, hold, prices);
        return dp[idx][hold] = max({buy, sell, skip});
    }

public:
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size() + 1, vector<int>(2, -1));
        return rec(0, 0, prices);
    }
};