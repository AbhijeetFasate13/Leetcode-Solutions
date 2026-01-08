class Solution {
    const int mod = 1e9 + 7;
    long long int binpow(long long a, long long int b) {
        a %= mod;
        long long int res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res % mod;
    }

public:
    int countGoodNumbers(long long n) {
        long long ans = (binpow(5, (n + 1) / 2) * binpow(4, n / 2)) % mod;
        return ans;
    }
};