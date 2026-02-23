class Solution {
public:
    int maxSide;
    bool solve(vector<int>& matchsticks, int i, vector<int>& lens) {
        if (i == matchsticks.size()) {
            return lens[0] == lens[1] and lens[1] == lens[2] and
                   lens[2] == lens[3];
        }

        for (int j = 0; j < 4; j++) {
            if (lens[j] + matchsticks[i] <= maxSide) {
                lens[j] += matchsticks[i];
                if (solve(matchsticks, i + 1, lens))
                    return true;
                lens[j] -= matchsticks[i];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4)
            return false;
        int totSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totSum % 4 != 0)
            return false;
        maxSide = totSum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > maxSide)
            return false;
        vector<int> lens(4);
        return solve(matchsticks, 0, lens);
    }
};