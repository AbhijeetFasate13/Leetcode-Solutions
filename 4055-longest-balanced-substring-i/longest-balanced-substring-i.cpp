class Solution {
    bool check(const vector<int>& arr) {
        int sameFreq = -1;
        for (const int& i : arr) {
            if (i == 0)
                continue;
            if (sameFreq == -1)
                sameFreq = i;
            else if (sameFreq != i)
                return false;
        }
        return true;
    }

public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 1;
        vector<int> freq(26);
        for (int i = 0; i < n - maxLen; i++) {
            fill(freq.begin(), freq.end(), 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (check(freq)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};