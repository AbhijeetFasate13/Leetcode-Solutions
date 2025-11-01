class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.size() == 2) {
            return s[0] == s[1];
        }
        string newS;
        for (int i = 0; i < s.size() - 1; i++) {
            int curr = (s[i] - '0');
            int next = (s[i + 1] - '0');
            newS += ((curr + next) % 10) + '0';
        }
        return hasSameDigits(newS);
    }
};