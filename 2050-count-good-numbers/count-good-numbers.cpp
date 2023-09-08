class Solution {
    const int MOD = 1e9+7;
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
public:
    int countGoodNumbers(long long n) {
        long long ans = binpow(20,n/2,MOD);
        if(!(n&1))return ans;
        return (ans*5)%MOD;
    }
};