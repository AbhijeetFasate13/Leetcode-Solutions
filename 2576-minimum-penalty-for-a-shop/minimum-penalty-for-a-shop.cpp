class Solution {
public:
    int bestClosingTime(string customers) {
        // if we close at ith hour every N i will give -1
        // but, if we add +1 (meaning good business) for every Y then
        // we can look four first lowest dip

        int score = 0, maxScore = 0, bestHour = -1;
        for (int i = 0; i < customers.size(); i++) {
            score += (customers[i] == 'Y' ? 1 : -1);
            if (score > maxScore) {
                maxScore = score;
                bestHour = i;
            }
        }
        return bestHour + 1;
    }
};