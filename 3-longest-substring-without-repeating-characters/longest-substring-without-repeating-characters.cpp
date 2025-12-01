class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size();
        unordered_map<char, int> freq;
        int maxLen = 0;
        while (r < n) {
            freq[s[r]]++;
            if (r - l + 1 > freq.size()) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) {
                    freq.erase(s[l]);
                }
                l++;
            }
            if (r - l + 1 == freq.size())
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};