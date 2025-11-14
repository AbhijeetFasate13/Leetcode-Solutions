class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n);
        for (int i = 0; i < shifts.size(); i++) {
            int l = shifts[i][0], r = shifts[i][1],
                k = shifts[i][2] == 1 ? 1 : -1;
            diff[l] += k;
            if (r + 1 < n) {
                diff[r + 1] -= k;
            }
        }
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            s[i] = ((s[i] - 'a' + (diff[i] % 26) + 26) % 26) + 'a';
        }
        return s;
    }
};