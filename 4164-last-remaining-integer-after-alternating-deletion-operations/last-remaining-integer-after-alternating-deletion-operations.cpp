class Solution {
public:
    long long lastInteger(long long n) {
        long long int len = n;
        long long int a = 1;
        long long int d = 1;
        long long int step = 1;
        while (len > 1) {
            if (step % 2 == 0 and len % 2 == 0) {
                a += d;
            }
            d *= 2;
            step++;
            len = (n - a) / d + 1;
        }
        return a;
    }
};