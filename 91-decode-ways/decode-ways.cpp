class Solution {
    int dp[101];

    int rec(int i, const string& s) {
        if (i >= s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = rec(i + 1, s);
        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                ans += rec(i + 2, s);
        }
        return dp[i] = ans;
    }

public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
};