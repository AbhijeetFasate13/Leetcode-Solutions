class Solution {
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n > 3 and (n % 6 != 1 and n % 6 != 5))
            return false;
        return n == 2 or n == 3 or n == 5 or n == 7 or n == 11 or n == 13 or
               n == 17 or n == 19;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(__builtin_popcount(i)))
                count++;
        }
        return count;
    }
};