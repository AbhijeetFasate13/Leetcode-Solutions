class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;

        long long commas = 0;
        long long base = 1000;
        while (n >= base) {
            commas += n - base + 1;
            base *= 1000;
        }
        return commas;
    }
};