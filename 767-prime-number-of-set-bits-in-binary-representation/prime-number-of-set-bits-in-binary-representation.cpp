class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;
        for (int i = left; i <= right; i++) {
            int numOfBits = __builtin_popcount(i);
            if (binary_search(primes.begin(), primes.end(), numOfBits)) {
                count++;
            }
        }
        return count;
    }
};