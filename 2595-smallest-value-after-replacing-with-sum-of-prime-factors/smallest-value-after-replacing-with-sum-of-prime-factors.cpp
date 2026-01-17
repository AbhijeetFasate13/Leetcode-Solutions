class Solution {
    int sumOfPrimeFactors(int n) {
        int sum = 0;
        while (n % 2 == 0) {
            sum += 2;
            n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                sum += i;
                n /= i;
            }
        }
        if (n > 1) {
            sum += n;
        }
        return sum;
    }

public:
    int smallestValue(int n) {
        int sum;
        while (true) {
            sum = sumOfPrimeFactors(n);
            if (sum == n) {
                break;
            }
            n = sum;
        }
        return n;
    }
};