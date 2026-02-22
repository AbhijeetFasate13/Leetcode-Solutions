class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> rows(numRows + 10);
        int n = s.size();
        int modder = 2 * numRows - 2;
        int sizeMinusOne = numRows - 1;
        int idx;
        for (int i = 0; i < n; i++) {
            idx = i % modder;
            if (idx > sizeMinusOne) {
                idx = sizeMinusOne - (idx % sizeMinusOne);
            }
            rows[idx].push_back(s[i]);
        }
        string ans;
        for (const string& s : rows) {
            ans += s;
        }
        return ans;
    }
};