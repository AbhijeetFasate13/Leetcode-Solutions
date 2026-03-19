class Solution {
    const int m = 1e9 + 7;

    long long binpow(long long a, long long b) {
        a %= m;
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    long long inv(long long a) {
        return binpow(a, m - 2);
    }

public:
    int sumOfNumbers(int l, int r, int k) {
        int n = r - l + 1;
        long long digitSum = ( (long long)(l + r) % m * n % m ) * inv(2) % m;
        long long times = binpow(n, k - 1);
        long long powOf10 = binpow(10, k);
        long long sumOfPowOf10 = ( (powOf10 - 1 + m) % m ) * inv(9) % m;

        long long ans = times % m;
        ans = ans * digitSum % m;
        ans = ans * sumOfPowOf10 % m;

        return ans;
    }
};