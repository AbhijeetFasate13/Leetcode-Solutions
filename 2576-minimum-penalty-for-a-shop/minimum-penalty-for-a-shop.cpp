class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefixY(n + 1), prefixN(n + 1);
        for (int i = 1; i <= n; i++) {
            prefixY[i] = prefixY[i - 1] + (customers[i-1] == 'Y');
            prefixN[i] = prefixN[i - 1] + (customers[i-1] == 'N');
        }
        int minPenalty = prefixY[n] - prefixY[0], minIdx = 0;
        for (int i = 1; i <= n; i++) {
            int lossOfBusinessDueToEarlyClose = prefixY[n] - prefixY[i];
            int lossOfBusinessDueToLateClose = prefixN[i - 1];
            if (minPenalty >
                lossOfBusinessDueToEarlyClose + lossOfBusinessDueToLateClose) {
                minPenalty = lossOfBusinessDueToEarlyClose +
                             lossOfBusinessDueToLateClose;
                minIdx = i;
            }
        }
        return minIdx;
    }
};