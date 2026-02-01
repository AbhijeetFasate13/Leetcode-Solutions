class Solution {
public:
    string reverseByType(string s) {
        string lower, special;
        for (const char& c : s) {
            if (c >= 'a' and c <= 'z') {
                lower = c + lower;
            } else {
                special = c + special;
            }
        }
        int lPtr = 0, sPtr = 0;
        for (char& c : s) {
            if (c >= 'a' and c <= 'z') {
                c = lower[lPtr++];
            } else {
                c = special[sPtr++];
            }
        }
        return s;
    }
};