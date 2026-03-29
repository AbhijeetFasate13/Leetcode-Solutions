class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq(26);
        for (int i = 0; i < s1.size(); i += 2) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }
        for (int i = 1; i < s1.size(); i += 2) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }
};