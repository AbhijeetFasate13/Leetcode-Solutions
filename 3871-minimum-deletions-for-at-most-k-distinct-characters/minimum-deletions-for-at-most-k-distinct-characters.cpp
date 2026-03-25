class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26);
        for (const char& c : s) {
            freq[c - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int deletions = 0;
        for (int i = k; i < 26; i++) {
            if (freq[i] == 0)
                break;
            deletions += freq[i];
        }
        return deletions;
    }
};