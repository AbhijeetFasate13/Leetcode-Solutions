class Solution {
public:
    int minCost(string colors, vector<int>& neededTimes) {
        int n = colors.size();
        if (n == 1) {
            return 0;
        }
        int totalTime = 0;
        int maxTime = neededTimes[0];

        for (int i = 1; i < n; i++) {
            if (colors[i - 1] == colors[i]) {
                totalTime += min(maxTime, neededTimes[i]);
                maxTime = max(maxTime, neededTimes[i]);
            } else {
                maxTime = neededTimes[i];
            }
        }
        return totalTime;
    }
};