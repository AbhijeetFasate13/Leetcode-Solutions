class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> alphaLow(26), alphaHigh(26);
        int count = 0;
        for (const char& c : word) {
            if (c >= 'a' and c <= 'z')
                alphaLow[c - 'a']++;
            else
                alphaHigh[c - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (alphaLow[i] and alphaHigh[i])
                count++;
        }
        return count;
    }
};