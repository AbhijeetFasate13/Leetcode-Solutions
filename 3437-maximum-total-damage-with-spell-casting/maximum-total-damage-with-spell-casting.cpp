class Solution {
    vector<long long> dp;
    long long rec(int idx, vector<int>& power, unordered_map<int, long long>& mp) {
        if (idx >= power.size())
            return 0;
        if (dp[idx] != INT_MIN) {
            return dp[idx];
        }
        int nextIdx = lower_bound(power.begin(), power.end(), power[idx] + 3) -
                      power.begin();
        long long take = power[idx] * mp[power[idx]] + rec(nextIdx, power, mp);
        long long skip = rec(idx + 1, power, mp);
        return dp[idx] = max(take, skip);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> mp;
        for (const auto& i : power) {
            mp[i]++;
        }
        sort(begin(power), end(power));
        dp.assign(power.size() + 1, INT_MIN);
        return rec(0, power, mp);
    }
};