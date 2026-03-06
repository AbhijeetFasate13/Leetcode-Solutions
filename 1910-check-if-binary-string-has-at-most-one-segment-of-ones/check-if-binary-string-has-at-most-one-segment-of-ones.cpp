class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenZero = false;
        for (const char& c : s) {
            if (c == '0') {
                seenZero = true;
            } else if (seenZero) {
                return false;
            }
        }
        return true;
    }
};