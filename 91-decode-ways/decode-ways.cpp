class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.size();
        if (s[0] == '0')
            return 0;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[1] == '0' ? 0 : 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (s.substr(i - 2, 2) >= "10" and s.substr(i - 2, 2) <= "26") {
                dp[i] += dp[i - 2];
                // cout << s.substr(i - 2, 2) << endl;
            }
        }
        return dp[n];
    }
};