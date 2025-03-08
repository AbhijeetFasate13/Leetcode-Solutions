class Solution {
    vector<int> primes;
    void sieve() {
        primes.resize(1e6 + 10, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= 1e6 + 10; i++) {
            if (primes[i]) {
                for (int j = i * i; j < 1e6 + 10; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }

public:
    Solution() { sieve(); }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2, -1);
        int minDiff = 1e9;
        int prev, curr;
        for (int i = left; i <= right; i++) {
            if (!primes[i])
                continue;
            cout << i << " ";
            if (ans[0] == -1) {
                ans[0] = i;
                prev = ans[0];
                continue;
            }
            if (ans[1] == -1) {
                ans[1] = i;
                curr = ans[1];
                minDiff = ans[1] - ans[0];
                continue;
            }
            prev = curr;
            curr = i;
            if (curr - prev < minDiff) {
                minDiff = curr - prev;
                ans[0] = prev;
                ans[1] = curr;
            }
        }
        if (ans[1] == -1) {
            ans = {-1, -1};
        }
        return ans;
    }
};