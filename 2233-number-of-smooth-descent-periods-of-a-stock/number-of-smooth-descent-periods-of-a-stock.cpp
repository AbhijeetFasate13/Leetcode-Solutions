class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int totalDescentPeriods = 0;
        int n = prices.size();
        long long int len = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i] - prices[i - 1] == -1) {
                len++;
            } else {
                totalDescentPeriods += len * (len + 1) / 2;
                len = 1;
            }
        }
        totalDescentPeriods += len * (len + 1) / 2;
        return totalDescentPeriods;
    }
};