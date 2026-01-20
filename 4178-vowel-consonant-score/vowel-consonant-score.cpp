class Solution {
    bool isVowel(const char& c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }

public:
    int vowelConsonantScore(string s) {
        int v = 0, co = 0;
        for (const char& c : s) {
            if (isVowel(c)) {
                v++;
            } else if (c >= 'a' and c <= 'z') {
                co++;
            }
        }
        if (co == 0)
            return 0;
        return v / co;
    }
};