class Solution {
    long long binpow(long long a, long long b, int mod = 1e9 + 7) {
        a %= mod;
        long long res = 1;
        while (b) {
            if (b & 1) {
                res *= a;
                res %= mod;
            }
            a *= a;
            a %= mod;
            b>>=1;
        }
        return res % mod;
    }

public:
    int countGoodNumbers(long long n) {
        long long a = binpow(5ll, (n + 1) / 2ll);
        long long b = binpow(4ll, n / 2ll);
        a *= b;
        a %= 1000000007;
        return a;
    }
};