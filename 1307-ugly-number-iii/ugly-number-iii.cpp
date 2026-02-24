class Solution {
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

    bool check(long long n, long long mid, long long a, long long b,
               long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc);

        long long count = mid / a + mid / b + mid / c;
        count -= (mid / ab + mid / bc + mid / ac);
        count += mid / abc;

        return count >= n;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1, r = 2e9;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (check(n, mid, a, b, c))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};