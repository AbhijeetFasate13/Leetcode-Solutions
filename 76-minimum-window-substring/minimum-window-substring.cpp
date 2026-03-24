class Solution {
    bool check(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 52; i++) {
            if (a[i] < b[i])
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        vector<int> tFreq(52);
        for (const char& c : t) {
            if (c >= 'a' && c <= 'z')
                tFreq[c - 'a']++;
            else
                tFreq[c - 'A' + 26]++;
        }

        int l = 0, n = s.size();
        vector<int> sFreq(52);

        int minLen = n + 1;
        int start = 0;

        for (int r = 0; r < n; r++) {
            char c = s[r];

            if (c >= 'a' && c <= 'z')
                sFreq[c - 'a']++;
            else
                sFreq[c - 'A' + 26]++;

            while (l <= r && check(sFreq, tFreq)) {
                if (minLen > r - l + 1) {
                    minLen = r - l + 1;
                    start = l;
                }

                c = s[l];
                if (c >= 'a' && c <= 'z')
                    sFreq[c - 'a']--;
                else
                    sFreq[c - 'A' + 26]--;

                l++;
            }
        }

        return (minLen == n + 1) ? "" : s.substr(start, minLen);
    }
};