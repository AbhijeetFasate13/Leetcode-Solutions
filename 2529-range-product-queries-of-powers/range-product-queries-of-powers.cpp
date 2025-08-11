class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> power;
        long long curr = 1;
        int temp = n;
        while (temp) {
            if (temp & 1)
                power.push_back(curr);
            curr <<= 1ll;
            temp >>= 1ll;
        }

        int m = power.size();
        vector<long long> prefix(m);
        prefix[0] = power[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * power[i]) % MOD;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                ans.push_back(prefix[r] % MOD);
            } else {
                long long numerator = prefix[r];
                long long denominator = prefix[l - 1];
                long long inv = modPow(denominator, MOD - 2);
                ans.push_back((numerator * inv) % MOD);
            }
        }
        return ans;
    }
};
