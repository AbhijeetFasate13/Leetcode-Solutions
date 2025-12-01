class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charFreq(26);
        int l = 0, maxFreq = 0;
        int maxLen = 0;
        for (int r = 0; r < s.size(); r++) {
            charFreq[s[r]-'A']++;
            maxFreq = max(maxFreq, charFreq[s[r]-'A']);
            int len = r - l + 1;
            if (len - maxFreq > k) {
                charFreq[s[l]-'A']--;
                l++;
            }
            if (len - maxFreq <= k) {
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};