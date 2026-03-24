class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3);
        int l = 0, n = s.size();
        int result = 0;
        for (int r = 0; r < n; r++) {
            count[s[r] - 'a']++;
            while (l <= r and count[0] > 0 and count[1] > 0 and count[2] > 0) {
                result += s.length() - r;
                count[s[l++] - 'a']--;
            }
        }
        return result;
    }
};