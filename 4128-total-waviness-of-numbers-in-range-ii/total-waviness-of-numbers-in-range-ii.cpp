class Solution {
    static inline int waves[570];
    static inline bool init = []() {
        int k = 0;

        for (int i = 0; i < 1000; i++) {
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = (i / 100) % 10;

            if ((b > max(a, c)) || (b < min(a, c))) {
                waves[k++] = i;
            }
        }

        return false;
    }();

public:
    long long totalWaviness(long long A, long long B) {
        return waveCount(B) - waveCount(A - 1);
    }

private:
    long long waveCount(long long num) {
        if (num < 100) {
            return 0;
        }

        return accumulate(begin(waves), end(waves), 0LL,
            [&](long long res, int pat) {
                return res + countWays(num, pat);
            });
    }

    long long countWays(long long num, int pat) {
        long long lead = (pat < 100);
        long long res = 0;
        long long p10 = 1;

        while (p10 * 100 <= num) {
            long long hi = num / (p10 * 1000);
            long long cur = (num / p10) % 1000;
            long long lo = num % p10;

            long long cnt = 0;
            long long add = 0;

            if (cur > pat) {
                cnt = hi - lead + 1;
            } else if (cur == pat) {
                cnt = max(0LL, hi - lead);
                add = lo + 1;
            } else {
                cnt = max(0LL, hi - lead);
            }

            res += cnt * p10 + add;
            p10 *= 10;
        }

        return res;
    }
};