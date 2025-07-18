class Solution {
    bool isEqual(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int m = s1.length(), n = s2.length();
        vector<int> freq1(26), freq2(26);
        for (int i = 0; i < m; i++) {
            freq1[s1[i] - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            freq2[s2[i] - 'a']++;
        }
        if (isEqual(freq1, freq2)) {
            return true;
        }
        for (int i = m; i < n; i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - m] - 'a']--;
            if (isEqual(freq1, freq2)) {
                return true;
            }
        }
        return false;
    }
};