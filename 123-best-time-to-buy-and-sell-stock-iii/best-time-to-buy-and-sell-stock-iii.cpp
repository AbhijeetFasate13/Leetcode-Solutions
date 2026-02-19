class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(3, vector<int>(2, 0));
        vector<vector<int>> prev(3, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int transactions = 0; transactions < 2; transactions++) {
                curr[transactions][1] =
                    max(prices[i] + prev[transactions + 1][0],
                        prev[transactions][1]);
                curr[transactions][0] = max(-prices[i] + prev[transactions][1],
                                            prev[transactions][0]);
            }
            prev = curr;
        }
        return prev[0][0];
    }
};
