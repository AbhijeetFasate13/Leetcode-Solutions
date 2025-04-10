class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return eval(finish, limit, s) - eval(start - 1, limit, s);
    }

private:
    long long eval(long long val, int limit, const string& s) {
        string digits = to_string(val);
        int prefixLength = digits.length() - s.length();

        if (prefixLength < 0) return 0;
        vector<vector<long long>> dp(prefixLength + 1, vector<long long>(2, 0));

        dp[prefixLength][0] = 1;
        dp[prefixLength][1] = digits.substr(prefixLength) >= s ? 1 : 0;

        for (int i = prefixLength - 1; i >= 0; --i) {
            int curr = digits[i] - '0';
            dp[i][0] = (limit + 1) * dp[i + 1][0];

            if (curr <= limit) {
                dp[i][1] = (long long)curr * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (long long)(limit + 1) * dp[i + 1][0];
            }
        }

        return dp[0][1];
    }
};