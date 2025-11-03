class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if (n == 1) {
            return 0;
        }
        int prev = 0, curr = 1;
        int timeRequired = 0;
        while (curr < n) {
            if (colors[prev] == colors[curr]) {
                if (neededTime[prev] > neededTime[curr]) {
                    timeRequired += neededTime[curr];
                } else {
                    timeRequired += neededTime[prev];
                    prev = curr - 1;
                    prev++;
                }
            } else {
                prev = curr - 1;
                prev++;
            }
            curr++;
        }
        return timeRequired;
    }
};