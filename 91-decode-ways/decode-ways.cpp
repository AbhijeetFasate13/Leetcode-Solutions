class Solution {
    vector<int> dp;
    bool belongsTo(int tens, int units, int l, int r) {
        int num = tens * 10 + units;
        return num >= l and num <= r;
    }
    int rec(int idx, const string& s) {
        if (idx >= s.size()) {
            return 1;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int curr = s[idx] - '0';
        int next = idx != s.size() - 1 ? s[idx + 1] - '0' : -1;
        int ways = 0;
        ways += (curr != 0) ? rec(idx + 1, s) : 0;
        if (next != -1) {
            ways += belongsTo(curr, next, 10, 26) ? rec(idx + 2, s) : 0;
        }
        return dp[idx] = ways;
    }

public:
    int numDecodings(string s) {
        dp.resize(s.size() + 1, -1);
        return rec(0, s);
    }
};