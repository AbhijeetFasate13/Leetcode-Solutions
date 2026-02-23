class Solution {
    bool rec(int idx, const int& target, vector<int>& lens,
             const vector<int>& matches) {
        if (idx == matches.size()) {
            return lens[0] == lens[1] and lens[1] == lens[2] and
                   lens[2] == lens[3];
        }
        for (int i = 0; i < 4; i++) {
            if (matches[idx] + lens[i] > target)
                continue;
            lens[i] += matches[idx];
            if (rec(idx + 1, target, lens, matches))
                return true;
            lens[i] -= matches[idx];
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> lens(4);
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;
        sum /= 4;
        return rec(0, sum, lens, matchsticks);
    }
};