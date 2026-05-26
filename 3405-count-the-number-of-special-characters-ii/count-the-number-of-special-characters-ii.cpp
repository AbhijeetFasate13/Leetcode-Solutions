class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> alphaLow(26, -1), alphaHigh(26, -1);
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' and word[i] <= 'z')
                alphaLow[word[i] - 'a'] = i;
            else if (alphaHigh[word[i] - 'A'] == -1)
                alphaHigh[word[i] - 'A'] = i;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (alphaLow[i] != -1 and alphaHigh[i] != -1 and
                alphaLow[i] < alphaHigh[i])
                count++;
        }
        return count;
    }
};