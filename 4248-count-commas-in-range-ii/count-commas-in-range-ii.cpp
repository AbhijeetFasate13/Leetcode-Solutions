class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;

        int digits = to_string(n).length();
        long long commas = (digits - 1) / 3;
        long long base = pow(10, digits - 1);
        return commas * (n - base + 1) + countCommas(base - 1);
    }
};