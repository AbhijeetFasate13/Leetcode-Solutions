class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefix(n + 1), prefixWithStrat(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + prices[i];
            prefixWithStrat[i + 1] =
                prefixWithStrat[i] + 1LL * prices[i] * strategy[i];
        }
        long long baseProfit = prefixWithStrat[n];
        for (int i = k - 1; i < n; i++) {
            long long leftSum = prefixWithStrat[i - k + 1];
            long long rightSum = prefixWithStrat[n] - prefixWithStrat[i + 1];
            long long currSum = prefix[i + 1] - prefix[i - k / 2 + 1];

            baseProfit = max(baseProfit, leftSum + currSum + rightSum);
        }
        return baseProfit;
    }
};
