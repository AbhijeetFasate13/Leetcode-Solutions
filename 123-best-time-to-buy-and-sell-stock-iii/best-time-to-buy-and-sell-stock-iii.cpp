class Solution {
    int dp[100005][3][2];

    int rec(int idx, int transactions, int stockBought, vector<int>& prices) {
        if (idx == prices.size() || transactions == 2)
            return 0;
        if (dp[idx][transactions][stockBought] != -1)
            return dp[idx][transactions][stockBought];
        int pick;
        if (stockBought) {
            pick = prices[idx] + rec(idx + 1, transactions + 1, 0, prices);
        } else {
            pick = -prices[idx] + rec(idx + 1, transactions, 1, prices);
        }
        int notPick = rec(idx + 1, transactions, stockBought, prices);
        return dp[idx][transactions][stockBought] = max(pick, notPick);
    }

public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, prices);
    }
};
