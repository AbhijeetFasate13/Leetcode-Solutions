class Solution {
    string convertToTimeString(const int& hours, const int& minutes) {
        string h = to_string(hours);
        string m = to_string(minutes);
        if (m.size() < 2) {
            m = '0' + m;
        }
        return h + ":" + m;
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int hours = 0; hours <= 11; hours++) {
            for (int minutes = 0; minutes <= 59; minutes++) {
                if (__builtin_popcount(hours) + __builtin_popcount(minutes) ==
                    turnedOn) {
                    ans.push_back(convertToTimeString(hours, minutes));
                }
            }
        }
        return ans;
    }
};