class Solution {
    vector<int> reduceSet(vector<int>& coins) {
        sort(begin(coins), end(coins));
        vector<int> newSet;
        int n = coins.size();
        for (int i = 0; i < n - 1; i++) {
            if (coins[i] != -1) {
                for (int j = i + 1; j < n; j++) {
                    if (coins[j] % coins[i] == 0) {
                        coins[j] = -1;
                    }
                }
                newSet.push_back(coins[i]);
            }
        }
        if (coins.back() != -1)
            newSet.push_back(coins.back());
        return newSet;
    }
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

    long long check(long long m, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;
        for (int i = 1; i <= (1 << n) - 1; i++) {
            long long l = 1;
            int bits = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    l = lcm(l, coins[j]);
                    bits++;
                }
            }
            if (l > m)
                continue;
            if (bits & 1) {
                ans += m / l;
            } else {
                ans -= m / l;
            }
        }
        return ans;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        coins = reduceSet(coins);
        int n = coins.size();
        long long l = 0, r = 1ll*coins[0] * k + 1;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            long long ans = check(m, coins);
            if (ans >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};