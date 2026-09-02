class Solution {
    const int mod = 1e9 + 7;

    int totalDigits(long long& x) { return to_string(x).size(); }

    int binpow(long long a, long long b) {
        a %= mod;
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res % mod;
    }

    int decode(long long& num) {
        long long width = num % 10;
        long long d = num / 10;
        long long x = d / binpow(10ll, totalDigits(d) - width);
        long long y = d - x * binpow(10ll, totalDigits(d) - width);
        return binpow(x, y);
    }

public:
    int sumDecoded(vector<long long>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum = (sum + decode(nums[i])) % mod;
        }
        return sum;
    }
};