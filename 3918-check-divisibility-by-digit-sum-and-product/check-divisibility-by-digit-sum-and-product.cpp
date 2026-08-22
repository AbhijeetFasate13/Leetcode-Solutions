class Solution {
    long long getDigitSum(int n) {
        long long sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    long long getDigitProd(int n) {
        long long prod = 1;
        while (n) {
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }

public:
    bool checkDivisibility(int n) {
        long long sum = getDigitSum(n);
        long long prod = getDigitProd(n);
        sum += prod;
        return n % sum == 0;
    }
};