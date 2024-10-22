class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        // if (n == 2)
        //     return 1;
        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;
        int count = 0;
        for (long long int i = 2; i < n; i++) {
            if (primes[i]) {
                count++;
                for (long long int j = i * i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        return count;
    }
};